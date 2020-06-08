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

  VW_DLL_PUBLIC VWStatus VWCreateFeatureSpace(VWFeatureSpace**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDestroyFeatureSpace(VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWFeatureSpaceGetName(const VWFeatureSpace*, const char** name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceSetName(const VWFeatureSpace*, const char* name, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWFeatureSpaceCopy(const VWFeatureSpace*, VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWFeatureSpaceGetFeatures(
      VWFeatureSpace*, const uint64_t** ft_indices, const float** ft_values, int* length, VWErrorString*);

  // invalidates pointers, feature_name is optional
  VW_DLL_PUBLIC VWStatus VWFeatureSpacePushFeature(
      VWFeatureSpace*, uint64_t ft_index, float ft_value, const char* feature_name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceSetFeatureAuditString(VWFeatureSpace*, size_t index, const char* feature_name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceGetFeatureAuditString(VWFeatureSpace*, size_t index, const char** feature_name, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceRemoveFeature(VWFeatureSpace*, int index, VWErrorString*);

#ifdef __cplusplus
}
#endif
