// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus vw_create_feature_space(
      VWFeatureSpace** feature_space_handle, bool audit, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_destroy_feature_space(
      VWFeatureSpace* feature_space_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_feature_space_copy(const VWFeatureSpace* dest_feature_space_handle,
      VWFeatureSpace* src_feature_space_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_feature_space_get_features(VWFeatureSpace* feature_space_handle, const uint64_t** ft_indices,
      const float** ft_values, int* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // invalidates pointers
  // Use at your own risk - ft_index must make sense
  VW_DLL_PUBLIC VWStatus vw_feature_space_push_hashed_feature(VWFeatureSpace* feature_space_handle,
      uint64_t ft_index, float ft_value, const char* audit_name, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_feature_space_push_anonymous_feature_float(VWFeatureSpace* feature_space_handle,
      const char* namespace_name, float ft_value, VWHasher* hasher, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_float(VWFeatureSpace* feature_space_handle,
      const char* namespace_name, const char* feature_name, float ft_value, VWHasher* hasher,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_feature_space_push_feature_string(VWFeatureSpace* feature_space_handle,
      const char* namespace_name, const char* feature_name, const char* ft_value, VWHasher* hasher, bool chain_hash,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_feature_space_remove_feature(
      VWFeatureSpace* feature_space_handle, int index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Will return nullptr if not in audit mode.
  VW_DLL_PUBLIC VWStatus vw_feature_space_get_audit_string(VWFeatureSpace* feature_space_handle, size_t index,
      const char** namespace_name, const char** feature_name, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
