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

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetPooledExample(
      VWWorkspace* workspace_handle, VWExample** example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceReturnPooledExample(
      VWWorkspace* workspace_handle, VWExample** example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
  VW_DLL_PUBLIC VWStatus VWExampleSetup(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpaceIndices(const VWExample* example_handle, const unsigned char** indices,
      size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExamplePushFeatureSpaceIndex(
      VWExample* example_handle, unsigned char value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus VWExampleRemoveFeatureSpaceIndex(
      VWExample* example_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureSpace(const VWExample* example_handle, unsigned char index,
      VWFeatureSpace**, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureSpace(VWExample* example_handle, unsigned char index, const VWFeatureSpace*,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetFeatureOffset(
      const VWExample* example_handle, int* feature_offset, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetFeatureOffset(
      VWExample* example_handle, int feature_offset, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetTag(
      const VWExample* example_handle, const char** tag, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetTag(
      VWExample* example_handle, const char* tag, int length, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetWeight(
      const VWExample* example_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetWeight(
      VWExample* example_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetLabel(
      const VWExample* example_handle, VWLabel** label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetLabel(VWExample* example_handle, VWLabel* label, VWLabelType label_type,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetPrediction(
      const VWExample* example_handle, VWPrediction** prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetPrediction(VWExample* example_handle, VWPrediction* prediction,
      VWPredictionType prediction_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetPartialPrediction(
      const VWExample* example_handle, float* partial_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleGetUpdatedPrediction(
      const VWExample* example_handle, float* updated_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleGetLoss(
      const VWExample* example_handle, float* loss, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleGetTotalSumFeatSq(
      const VWExample* example_handle, float* total_sum_feat_sq, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWExampleGetTestOnly(
      const VWExample* example_handle, bool* test_only, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWExampleSetTestOnly(
      VWExample* example_handle, bool test_only, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
