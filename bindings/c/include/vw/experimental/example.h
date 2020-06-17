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

  VW_DLL_PUBLIC VWStatus vw_create_example(
      VWExample** example_handle, VWAllocator* allocator, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_destroy_example(
      VWExample* example_handle, VWAllocator* allocator, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
  VW_DLL_PUBLIC VWStatus vw_example_setup(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_feature_space_indices(const VWExample* example_handle,
      const unsigned char** indices, size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_example_push_feature_space_index(
      VWExample* example_handle, unsigned char value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus vw_example_remove_feature_space_index(
      VWExample* example_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // TODO specify audit or not when you get
  VW_DLL_PUBLIC VWStatus vw_example_get_feature_space(const VWExample* example_handle, unsigned char index,
      VWFeatureSpace** feature_space_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_feature_space(VWExample* example_handle, unsigned char index,
      const VWFeatureSpace* feature_space_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_feature_offset(
      const VWExample* example_handle, int* feature_offset, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_feature_offset(
      VWExample* example_handle, int feature_offset, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_tag(
      const VWExample* example_handle, const char** tag, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_tag(
      VWExample* example_handle, const char* tag, int length, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_weight(
      const VWExample* example_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_weight(
      VWExample* example_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_label(
      const VWExample* example_handle, VWLabel** label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_label(VWExample* example_handle, VWLabel* label, VWLabelType label_type,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_prediction(
      const VWExample* example_handle, VWPrediction** prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_prediction(VWExample* example_handle, VWPrediction* prediction,
      VWPredictionType prediction_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_partial_prediction(
      const VWExample* example_handle, float* partial_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_get_updated_prediction(
      const VWExample* example_handle, float* updated_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_get_loss(
      const VWExample* example_handle, float* loss, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_get_total_sum_feat_sq(
      const VWExample* example_handle, float* total_sum_feat_sq, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_example_get_test_only(
      const VWExample* example_handle, bool* test_only, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_example_set_test_only(
      VWExample* example_handle, bool test_only, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
