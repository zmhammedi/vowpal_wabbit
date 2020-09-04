// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/feature_space.h"
#include <limits>

#include "error_handling.h"
#include "interop_helper.h"
#include "hasher.h"

#include "parse_primitives.h"

VW_DLL_PUBLIC VWStatus vw_create_feature_space(
    VWFeatureSpace** feature_space_handle, bool audit, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  auto* feature_space = new features();
  feature_space->audit = audit;
  *feature_space_handle = to_opaque(feature_space);
  return VW_success;
}
CATCH_RETURN(err_info_container)

VW_DLL_PUBLIC VWStatus vw_destroy_feature_space(
    VWFeatureSpace* feature_space_handle, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  delete from_opaque(feature_space_handle);
  return VW_success;
}
CATCH_RETURN(err_info_container)

VW_DLL_PUBLIC VWStatus vw_feature_space_copy(VWFeatureSpace* dest_feature_space_handle,
    const VWFeatureSpace* src_feature_space_handle, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(dest_feature_space_handle, err_info_container);
  ARG_NOT_NULL(src_feature_space_handle, err_info_container);

  auto* dest_fs = from_opaque(dest_feature_space_handle);
  const auto* src_fs = from_opaque(src_feature_space_handle);
  dest_fs->deep_copy_from(*src_fs);
  return VW_success;
}
CATCH_RETURN(err_info_container)

VW_DLL_PUBLIC VWStatus vw_feature_space_get_features(const VWFeatureSpace* feature_space_handle,
    const uint64_t** ft_indices, const float** ft_values, int* length, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  ARG_NOT_NULL(ft_indices, err_info_container);
  ARG_NOT_NULL(ft_values, err_info_container);
  ARG_NOT_NULL(length, err_info_container);

  const auto* fs = from_opaque(feature_space_handle);
  *ft_indices = &fs->indicies[0];
  *ft_values = &fs->values[0];
  *length = fs->indicies.size();
  return VW_success;
}
CATCH_RETURN(err_info_container)

// invalidates pointers
// Use at your own risk - ft_index must make sense
VW_DLL_PUBLIC VWStatus vw_feature_space_push_hashed_feature(VWFeatureSpace* feature_space_handle, uint64_t ft_index,
    float ft_value, const char* audit_namespace_name, const char* audit_feature_name,
    VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);

  auto* feature_space = from_opaque(feature_space_handle);
  if (feature_space->audit)
  {
    ARG_NOT_NULL(audit_feature_name, err_info_container);
    ARG_NOT_NULL(audit_namespace_name, err_info_container);
  }

  feature_space->push_back(ft_value, ft_index);

  if (feature_space->audit)
  {
    feature_space->space_names.push_back(
      std::make_shared<audit_strings>(audit_namespace_name, audit_feature_name));
  }

  return VW_success;
}
CATCH_RETURN(err_info_container)

int64_t find_next_available_anonymous_slot(const features& fs, uint64_t namespace_hash)
{
  // If we don't sort the list we need to scan the indices for every slot. Potentially being m (anonymous features) * n
  // (fs size) Sorting guarantees one scan of the list after the nlog(n) sort.
  std::vector<uint64_t> temp(fs.indicies.begin(), fs.indicies.end());
  std::sort(temp.begin(), temp.end());

  uint64_t current = namespace_hash;
  for (auto index : temp)
  {
    // If the current index is the current anonymous value, the slot is taken so try the next.
    if (index == current)
    {
      current++;
    }
    if (index != current)
    {
      // This current slot is free, so we can return it and be done.
      return current;
    }
  }

  // The entire features list contains anonymous features - so we can use the next slot.
  return current;
}

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_anonymous_feature_float(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, float ft_value, VWHasher* hasher_handle, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  ARG_NOT_NULL(namespace_name, err_info_container);
  ARG_NOT_NULL(hasher_handle, err_info_container);
  auto* feature_space = from_opaque(feature_space_handle);
  auto* hasher = from_opaque(hasher_handle);

  auto namespace_hash = hasher->_hash_func(namespace_name, strlen(namespace_name), hasher->_hash_seed);
  auto anonymous_slot = find_next_available_anonymous_slot(*feature_space, namespace_hash);
  feature_space->push_back(ft_value, anonymous_slot);

  if (feature_space->audit)
  {
    feature_space->space_names.push_back(std::make_shared<audit_strings>(namespace_name, ""));
  }

  return VW_success;
}
CATCH_RETURN(err_info_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_float(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, const char* feature_name, float ft_value, VWHasher* hasher_handle,
    VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  ARG_NOT_NULL(namespace_name, err_info_container);
  ARG_NOT_NULL(hasher_handle, err_info_container);
  auto* feature_space = from_opaque(feature_space_handle);
  auto* hasher = from_opaque(hasher_handle);

  auto namespace_hash = hasher->_hash_func(namespace_name, strlen(namespace_name), hasher->_hash_seed);
  auto feature_hash = hasher->_hash_func(feature_name, strlen(feature_name), namespace_hash);
  // Should this operation occur here or when setup example is done?
  feature_hash = feature_hash & hasher->_parse_mask;
  feature_space->push_back(ft_value, feature_hash);

  if (feature_space->audit)
  {
    feature_space->space_names.push_back(std::make_shared<audit_strings>(namespace_name, feature_name));
  }

  return VW_success;
}
CATCH_RETURN(err_info_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_string(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, const char* feature_name, const char* ft_value, VWHasher* hasher_handle,
    bool chain_hash, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  ARG_NOT_NULL(namespace_name, err_info_container);
  ARG_NOT_NULL(hasher_handle, err_info_container);
  auto* feature_space = from_opaque(feature_space_handle);
  auto* hasher = from_opaque(hasher_handle);

  auto namespace_hash = hasher->_hash_func(namespace_name, strlen(namespace_name), hasher->_hash_seed);
  auto feature_name_hash = hasher->_hash_func(feature_name, strlen(feature_name), namespace_hash);

  uint64_t hash = feature_name_hash;
  if (chain_hash)
  {
    hash = hasher->_hash_func(ft_value, strlen(ft_value), feature_name_hash);
  }

  hash &= hasher->_parse_mask;
  feature_space->push_back(1.f, hash);

  if (feature_space->audit)
  {
    if (chain_hash)
    {
      std::stringstream ss;
      ss << feature_name << "^" << ft_value;
      feature_space->space_names.push_back(audit_strings_ptr(new audit_strings(namespace_name, ss.str())));
    }
    else
    {
      feature_space->space_names.push_back(audit_strings_ptr(new audit_strings(namespace_name, feature_name)));
    }
  }

  return VW_success;
}
CATCH_RETURN(err_info_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_remove_feature(
    VWFeatureSpace* feature_space_handle, int index, VWErrorInfo* err_info_container) noexcept
try
{
  // Can't remove at an index...
  return VW_not_implemented;
}
CATCH_RETURN(err_info_container)

// Will return nullptr if not in audit mode.
VW_DLL_PUBLIC VWStatus vw_feature_space_get_audit_string(VWFeatureSpace* feature_space_handle, size_t index,
    const char** namespace_name, const char** feature_name, VWErrorInfo* err_info_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_info_container);
  ARG_NOT_NULL(namespace_name, err_info_container);
  ARG_NOT_NULL(feature_name, err_info_container);

  auto* feature_space = from_opaque(feature_space_handle);

  if (index >= feature_space->space_names.size())
  {
    SET_IF_EXISTS(err_info_container, "Index out of bounds in vw_feature_space_get_audit_string");
    return VW_index_not_found;
  }

  const auto& audit_string = feature_space->space_names[index];
  *namespace_name = audit_string->first.c_str();
  *feature_name = audit_string->second.c_str();

  return VW_success;
}
CATCH_RETURN(err_info_container)
