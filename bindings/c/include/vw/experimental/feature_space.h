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

  VW_DLL_PUBLIC VWStatus VWCreateFeatureSpace(VWFeatureSpace**, bool audit, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDestroyFeatureSpace(VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWFeatureSpaceCopy(const VWFeatureSpace*, VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWFeatureSpaceGetFeatures(
      VWFeatureSpace*, const uint64_t** ft_indices, const float** ft_values, int* length, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWFeatureSpacePushAnonymousFeatureFloat(
      VWFeatureSpace*, float ft_value, const char* namespace_name, VWHasher* hasher, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWFeatureSpacePushFeatureFloat(VWFeatureSpace*, float ft_value, const char* namespace_name,
      const char* feature_name, VWHasher* hasher, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWFeatureSpacePushFeatureString(VWFeatureSpace*, const char* ft_value,
      const char* namespace_name, const char* feature_name, VWHasher* hasher, bool chain_hash, VWErrorString*);

  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceRemoveFeature(VWFeatureSpace*, int index, VWErrorString*);

  // Will return nullptr if not in audit mode.
  VW_DLL_PUBLIC VWStatus VWFeatureSpaceGetAuditString(
      VWFeatureSpace*, size_t index, const char** namespace_name, const char** feature_name, VWErrorString*);

#ifdef __cplusplus
}
#endif
