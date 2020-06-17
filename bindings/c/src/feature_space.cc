// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/feature_space.h"

#include "error_handling.h"
#include "interop_helper.h"

VW_DLL_PUBLIC VWStatus vw_create_feature_space(
    VWFeatureSpace** feature_space_handle, bool audit, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_destroy_feature_space(
    VWFeatureSpace* feature_space_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_feature_space_copy(VWFeatureSpace* dest_feature_space_handle,
    const VWFeatureSpace* src_feature_space_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(dest_feature_space_handle, err_str_container);
  ARG_NOT_NULL(src_feature_space_handle, err_str_container);

  auto* dest_fs = from_opaque(dest_feature_space_handle);
  const auto* src_fs = from_opaque(src_feature_space_handle);
  dest_fs->deep_copy_from(*src_fs);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_feature_space_get_features(const VWFeatureSpace* feature_space_handle,
    const uint64_t** ft_indices, const float** ft_values, int* length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(feature_space_handle, err_str_container);
  ARG_NOT_NULL(ft_indices, err_str_container);
  ARG_NOT_NULL(ft_values, err_str_container);
  ARG_NOT_NULL(length, err_str_container);

  const auto* fs = from_opaque(feature_space_handle);
  *ft_indices = &fs->indicies[0];
  *ft_values = &fs->values[0];
  *length = fs->indicies.size();
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
// Use at your own risk - ft_index must make sense
VW_DLL_PUBLIC VWStatus vw_feature_space_push_hashed_feature(VWFeatureSpace* feature_space_handle, uint64_t ft_index,
    float ft_value, const char* audit_name, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_anonymous_feature_float(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, float ft_value, VWHasher* hasher, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_float(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, const char* feature_name, float ft_value, VWHasher* hasher,
    VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_string(VWFeatureSpace* feature_space_handle,
    const char* namespace_name, const char* feature_name, const char* ft_value, VWHasher* hasher, bool chain_hash,
    VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_feature_space_remove_feature(
    VWFeatureSpace* feature_space_handle, int index, VWErrorString* err_str_container) noexcept
try
{
  // Can't remove at an index...
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

// Will return nullptr if not in audit mode.
VW_DLL_PUBLIC VWStatus vw_feature_space_get_audit_string(VWFeatureSpace* feature_space_handle, size_t index,
    const char** namespace_name, const char** feature_name, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)
