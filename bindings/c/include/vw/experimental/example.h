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
  VW_DLL_PUBLIC vw_status setup_example(vw_workspace*, vw_example*, vw_err_str*);

  VW_DLL_PUBLIC vw_status get_pooled_example(vw_workspace*, vw_example**, vw_err_str*);
  VW_DLL_PUBLIC vw_status return_pooled_example(vw_workspace*, vw_example**, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_feature_space_indices(
      const vw_example*, const unsigned char** indices, size_t* length, vw_err_str*);
  // invalidates pointers
  VW_DLL_PUBLIC vw_status example_push_feature_space_index(vw_example*, unsigned char value, vw_err_str*);
  // invalidates pointers
  VW_DLL_PUBLIC vw_status example_remove_feature_space_index(vw_example*, size_t index, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_feature_space(const vw_example*, size_t index, vw_feature_space**, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_feature_space(vw_example*, size_t index, const vw_feature_space*, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_feature_offset(const vw_example*, int* feature_offset, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_feature_offset(vw_example*, int feature_offset, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_tag(const vw_example*, const char** tag, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_tag(vw_example*, const char* tag, int length, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_weight(const vw_example*, float* weight, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_weight(vw_example*, float weight, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_label(const vw_example*, void** label, vw_label_type, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_label(vw_example*, void* label, vw_label_type, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_prediction(const vw_example*, void** prediction, vw_prediction_type, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_prediction(vw_example*, void* prediction, vw_prediction_type, vw_err_str*);

  VW_DLL_PUBLIC vw_status get_partial_prediction(const vw_example*, float*, vw_err_str*);
  VW_DLL_PUBLIC vw_status get_updated_prediction(const vw_example*, float*, vw_err_str*);
  VW_DLL_PUBLIC vw_status get_loss(const vw_example*, float*, vw_err_str*);
  VW_DLL_PUBLIC vw_status get_total_sum_feat_sq(const vw_example*, float*, vw_err_str*);

  VW_DLL_PUBLIC vw_status example_get_test_only(const vw_example*, bool* test_only, vw_err_str*);
  VW_DLL_PUBLIC vw_status example_set_test_only(vw_example*, bool test_only, vw_err_str*);

#ifdef __cplusplus
}
#endif
