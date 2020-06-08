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

  // Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
  VW_DLL_PUBLIC VWStatus VWSetupExample(VWWorkspace*, VWExample*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWGetPooledExample(VWWorkspace*, VWExample**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWReturnPooledExample(VWWorkspace*, VWExample**, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpaceIndices(
      const VWExample*, const unsigned char** indices, size_t* length, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExamplePushFeatureSpaceIndex(VWExample*, unsigned char value, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExampleRemoveFeatureSpaceIndex(VWExample*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpace(const VWExample*, size_t index, VWFeatureSpace**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureSpace(VWExample*, size_t index, const VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureOffset(const VWExample*, int* feature_offset, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureOffset(VWExample*, int feature_offset, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetTag(const VWExample*, const char** tag, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetTag(VWExample*, const char* tag, int length, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetWeight(const VWExample*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetWeight(VWExample*, float weight, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetLabel(const VWExample*, void** label, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetLabel(VWExample*, void* label, VWLabelType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetPrediction(const VWExample*, void** prediction, VWPredictionType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetPrediction(VWExample*, void* prediction, VWPredictionType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetPartialPrediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetUpdatedPrediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetLoss(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleGetTotalSumFeatSq(const VWExample*, float*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWExampleGetTestOnly(const VWExample*, bool* test_only, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWExampleSetTestOnly(VWExample*, bool test_only, VWErrorString*);

#ifdef __cplusplus
}
#endif
