// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <cstddef>
#include "exports.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC vw_status allocate_feature_space(vw_feature_space**, vw_err_str*);
  VW_DLL_PUBLIC vw_status deallocate_feature_space(vw_feature_space*, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_set_feature_space_name(const vw_feature_space*, const char* name, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_get_feature_space_name(const vw_feature_space*, const char** name, vw_err_str*);

  VW_DLL_PUBLIC vw_status feature_space_copy(const vw_feature_space*, vw_feature_space*, vw_err_str*);

  VW_DLL_PUBLIC vw_status feature_space_get_features(
      vw_feature_space*, const uint64_t** ft_indices, const float** ft_values, int* length, vw_err_str*);

  // invalidates pointers, feature_name is optional
  VW_DLL_PUBLIC vw_status feature_space_push_feature(
      vw_feature_space*, uint64_t ft_index, float ft_value, const char* feature_name, vw_err_str*);
  VW_DLL_PUBLIC vw_status feature_space_set_feat_audit_str(vw_feature_space*, size_t index, const char* feature_name, vw_err_str*);
  VW_DLL_PUBLIC vw_status feature_space_get_feat_audit_str(vw_feature_space*, size_t index, const char** feature_name, vw_err_str*);

  // invalidates pointers
  VW_DLL_PUBLIC vw_status feature_space_remove_feature(vw_feature_space*, int index, vw_err_str*);


#ifdef __cplusplus
}
#endif
