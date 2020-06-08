// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <stddef.h>
#include "exports.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus allocate_feature_space(VWFeatureSpace**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus deallocate_feature_space(VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_set_feature_space_name(const VWFeatureSpace*, const char* name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_get_feature_space_name(const VWFeatureSpace*, const char** name, VWErrorString*);

  VW_DLL_PUBLIC VWStatus feature_space_copy(const VWFeatureSpace*, VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus feature_space_get_features(
      VWFeatureSpace*, const uint64_t** ft_indices, const float** ft_values, int* length, VWErrorString*);

  // invalidates pointers, feature_name is optional
  VW_DLL_PUBLIC VWStatus feature_space_push_feature(
      VWFeatureSpace*, uint64_t ft_index, float ft_value, const char* feature_name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus feature_space_set_feat_audit_str(VWFeatureSpace*, size_t index, const char* feature_name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus feature_space_get_feat_audit_str(VWFeatureSpace*, size_t index, const char** feature_name, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus feature_space_remove_feature(VWFeatureSpace*, int index, VWErrorString*);


#ifdef __cplusplus
}
#endif
