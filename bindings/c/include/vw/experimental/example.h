// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <cstddef>

#include "exports.h"
#include "types.h"

#include "feature_space.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetPooledExample(VWWorkspace*, VWExample**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceReturnPooledExample(VWWorkspace*, VWExample**, VWErrorString*);

  // Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
  VW_DLL_PUBLIC VWStatus VWExampleSetup(VWWorkspace*, VWExample*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpaceIndices(
      const VWExample*, const unsigned char** indices, size_t* length, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExamplePushFeatureSpaceIndex(VWExample*, unsigned char value, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExampleRemoveFeatureSpaceIndex(VWExample*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpace(const VWExample*, unsigned char index, VWFeatureSpace**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureSpace(VWExample*, unsigned char index, const VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureOffset(const VWExample*, int* feature_offset, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureOffset(VWExample*, int feature_offset, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetTag(const VWExample*, const char** tag, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetTag(VWExample*, const char* tag, int length, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetWeight(const VWExample*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetWeight(VWExample*, float weight, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetLabel(const VWExample*, VWLabel** label, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetLabel(VWExample*, VWLabel* label, VWLabelType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetPrediction(const VWExample*, VWPrediction** prediction, VWPredictionType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetPrediction(VWExample*, VWPrediction* prediction, VWPredictionType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetPartialPrediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetUpdatedPrediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetLoss(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetTotalSumFeatSq(const VWExample*, float*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetTestOnly(const VWExample*, bool* test_only, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetTestOnly(VWExample*, bool test_only, VWErrorString*);

#ifdef __cplusplus
}
#endif
