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

  vw_status allocate_simple_label(vw_simple_label**);
  vw_status deallocate_simple_label(vw_simple_label*);

  vw_status simple_label_get_label(vw_simple_label*, float*);
  vw_status simple_label_set_label(vw_simple_label*, float);
  vw_status simple_label_get_weight(vw_simple_label*, float*);
  vw_status simple_label_set_weight(vw_simple_label*, float);
  vw_status simple_label_get_initial(vw_simple_label*, float*);
  vw_status simple_label_set_initial(vw_simple_label*, float);

  vw_status allocate_multiclass_label(vw_multiclass_label**);
  vw_status deallocate_multiclass_label(vw_multiclass_label*);
  vw_status multiclass_label_get_label(vw_multiclass_label*, uint32_t*);
  vw_status multiclass_label_set_label(vw_multiclass_label*, uint32_t);
  vw_status multiclass_label_get_weight(vw_multiclass_label*, float*);
  vw_status multiclass_label_set_weight(vw_multiclass_label*, float);

  vw_status allocate_cs_label(vw_cs_label**);
  vw_status deallocate_cs_label(vw_cs_label*);
  vw_status cs_label_get_length(vw_cs_label*, int*);
  vw_status cs_label_get_item(
      vw_cs_label*, int index, float* x, uint32_t* class_index, float* partial_prediction, float* wap_value);
  vw_status cs_label_set_item(
      vw_cs_label*, int index, float x, uint32_t class_index, float partial_prediction, float wap_value);
  vw_status cs_label_push_item(vw_cs_label*, float x, uint32_t class_index, float partial_prediction, float wap_value);
  vw_status cs_label_remove_item(vw_cs_label*, int index);

  vw_status allocate_cb_label(vw_cb_label**);
  vw_status deallocate_cb_label(vw_cb_label*);
  vw_status cb_label_get_length(vw_cb_label*, int*);
  vw_status cb_label_get_weight(vw_cb_label*, float*);
  vw_status cb_label_set_weight(vw_cb_label*, float);
  vw_status cb_label_get_item(
      vw_cb_label*, int index, float* cost, uint32_t* action, float* probability, float* partial_prediction);
  vw_status cb_label_set_item(
      vw_cb_label*, int index, float cost, uint32_t action, float probability, float partial_prediction);
  vw_status cb_label_push_item(vw_cb_label*, float cost, uint32_t action, float probability, float partial_prediction);
  vw_status cb_label_remove_item(vw_cb_label*, int index);

  vw_status allocate_ccb_label(vw_ccb_label**);
  vw_status deallocate_ccb_label(vw_ccb_label*);
  vw_status ccb_label_get_type(vw_ccb_label*, uint8_t* type);
  vw_status ccb_label_set_type(vw_ccb_label*, uint8_t type);
  vw_status ccb_label_get_weight(vw_ccb_label*, float* weight);
  vw_status ccb_label_set_weight(vw_ccb_label*, float weight);
  vw_status ccb_label_get_explicit_included_actions(const vw_ccb_label*, uint32_t** indices, int* length);
  vw_status ccb_label_push_explicit_included_actions(vw_example*, uint32_t value);
  vw_status ccb_label_remove_explicit_included_actions(vw_example*, int index);

  vw_status allocate_ccb_outcome(vw_ccb_outcome**);
  vw_status deallocate_ccb_outcome(vw_ccb_outcome*);
  // may be nullptr
  vw_status ccb_label_get_outcome(vw_ccb_label*, vw_ccb_outcome** outcome);
  // may be nullptr
  vw_status ccb_label_set_outcome(vw_ccb_label*, vw_ccb_outcome* outcome);
  vw_status ccb_outcome_get_cost(vw_ccb_outcome*, float* cost);
  vw_status ccb_outcome_set_cost(vw_ccb_outcome*, float cost);
  vw_status ccb_outcome_get_length(vw_ccb_outcome*, int*);
  vw_status ccb_outcome_get_item(vw_ccb_outcome*, int index, uint32_t* action, float* score);
  vw_status ccb_outcome_set_item(vw_ccb_outcome*, int index, uint32_t action, float score);
  vw_status ccb_outcome_push_item(vw_ccb_outcome*, uint32_t action, float score);
  vw_status ccb_outcome_remove_item(vw_ccb_outcome*, int index);

  vw_status allocate_slates_label(vw_slates_label**);
  vw_status deallocate_slates_label(vw_slates_label*);
  vw_status slates_label_get_type(vw_slates_label*, uint8_t* type);
  vw_status slates_label_set_type(vw_slates_label*, uint8_t type);
  vw_status slates_label_get_weight(vw_slates_label*, float* weight);
  vw_status slates_label_set_weight(vw_slates_label*, float weight);
  vw_status slates_label_get_cost(vw_slates_label*, float* cost);
  vw_status slates_label_set_cost(vw_slates_label*, float cost);
  vw_status slates_label_get_labeled(vw_slates_label*, bool* labeled);
  vw_status slates_label_set_labeled(vw_slates_label*, bool labeled);
  vw_status slates_label_get_slot_id(vw_slates_label*, uint32_t* slot_id);
  vw_status slates_label_set_slot_id(vw_slates_label*, uint32_t slot_id);
  vw_status slates_label_get_length(vw_slates_label*, int*);
  vw_status slates_label_get_item(vw_slates_label*, int index, uint32_t* action, float* score);
  vw_status slates_label_set_item(vw_slates_label*, int index, uint32_t action, float score);
  vw_status slates_label_push_item(vw_slates_label*, uint32_t action, float score);
  vw_status slates_label_remove_item(vw_slates_label*, int index);

  vw_status allocate_cb_eval_label(vw_cb_eval_label**);
  vw_status deallocate_cb_eval_label(vw_cb_eval_label*);
  vw_status cb_eval_label_get_cb_label(vw_cb_eval_label*, vw_cb_label* cb_label);
  vw_status cb_eval_label_set_cb_label(vw_cb_eval_label*, vw_cb_label cb_label);
  vw_status cb_eval_label_get_action(vw_cb_eval_label*, uint32_t* action);
  vw_status cb_eval_label_set_action(vw_cb_eval_label*, uint32_t action);

  vw_status allocate_multilabels_label(vw_multilabels_label**);
  vw_status deallocate_multilabels_label(vw_multilabels_label*);
  vw_status multilabels_label_get(vw_multilabels_label*, uint32_t** multilabels, int* length);
  vw_status multilabels_label_push(vw_multilabels_label*, uint32_t value);
  vw_status multilabels_label_remove(vw_multilabels_label*, int index);

#ifdef __cplusplus
}
#endif
