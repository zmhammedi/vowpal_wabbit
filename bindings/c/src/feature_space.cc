// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/feature_space.h"

#include "error_handling.h"

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

VW_DLL_PUBLIC VWStatus vw_feature_space_copy(const VWFeatureSpace* dest_feature_space_handle,
    VWFeatureSpace* src_feature_space_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_feature_space_get_features(VWFeatureSpace* feature_space_handle, const uint64_t** ft_indices,
    const float** ft_values, int* length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
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



// VW_DLL_PUBLIC VWStatus feature_space_copy(const VWFeatureSpace* c_features_source, VWFeatureSpace* c_features_dest)
// {
//   const auto* fs_source = reinterpret_cast<const features*>(c_features_source);
//   auto* fs_dest = reinterpret_cast<features*>(c_features_dest);
//   fs_dest->deep_copy_from(*fs_source);
//   return VW_SUCCESS;
// }

// VW_DLL_PUBLIC VWStatus allocate_feature_space(VWFeatureSpace** c_features)
// {
//   *c_features = reinterpret_cast<VWFeatureSpace*>(new features);
//   return VW_SUCCESS;
// }

// VW_DLL_PUBLIC VWStatus deallocate_feature_space(VWFeatureSpace* c_features)
// {
//   delete reinterpret_cast<features*>(c_features);
//   return VW_SUCCESS;
// }

// VW_DLL_PUBLIC VWStatus feature_space_get_features(
//     VWFeatureSpace* c_features, uint64_t** ft_indices, float** ft_values, int* length)
// {
//   auto* fs = reinterpret_cast<features*>(c_features);
//   *ft_indices = &fs->indicies[0];
//   *ft_values = &fs->values[0];
//   *length = fs->indicies.size();
//   return VW_SUCCESS;
// }

// // invalidates pointers
// VW_DLL_PUBLIC VWStatus feature_space_push_feature(VWFeatureSpace* c_features, uint64_t ft_index, float ft_value)
// {
//   auto* fs = reinterpret_cast<features*>(c_features);
//   fs->indicies.push_back(ft_index);
//   fs->values.push_back(ft_value);
//   return VW_SUCCESS;
// }

// // invalidates pointers
// VW_DLL_PUBLIC VWStatus feature_space_remove_feature(VWFeatureSpace*, int index)
// {
//   // Can't remove at an index...
//   return VW_NOT_IMPLEMENTED;
// }