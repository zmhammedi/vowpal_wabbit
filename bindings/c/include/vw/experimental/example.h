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
  VW_DLL_PUBLIC VWStatus setup_example(VWWorkspace*, VWExample*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus get_pooled_example(VWWorkspace*, VWExample**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus return_pooled_example(VWWorkspace*, VWExample**, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_feature_space_indices(
      const VWExample*, const unsigned char** indices, size_t* length, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus example_push_feature_space_index(VWExample*, unsigned char value, VWErrorString*);
  // invalidates pointers
  VW_DLL_PUBLIC VWStatus example_remove_feature_space_index(VWExample*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_feature_space(const VWExample*, size_t index, VWFeatureSpace**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_feature_space(VWExample*, size_t index, const VWFeatureSpace*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_feature_offset(const VWExample*, int* feature_offset, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_feature_offset(VWExample*, int feature_offset, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_tag(const VWExample*, const char** tag, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_tag(VWExample*, const char* tag, int length, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_weight(const VWExample*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_weight(VWExample*, float weight, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_label(const VWExample*, void** label, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_label(VWExample*, void* label, VWLabelType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_prediction(const VWExample*, void** prediction, VWPredictionType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_prediction(VWExample*, void* prediction, VWPredictionType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus get_partial_prediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_updated_prediction(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_loss(const VWExample*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_total_sum_feat_sq(const VWExample*, float*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus example_get_test_only(const VWExample*, bool* test_only, VWErrorString*);
  VW_DLL_PUBLIC VWStatus example_set_test_only(VWExample*, bool test_only, VWErrorString*);

#ifdef __cplusplus
}
#endif
