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

  VW_DLL_PUBLIC VWStatus VWCreateLabel(void**, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDestroyLabel(void*, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDefaultLabel(void*, VWLabelType, VWErrorString*);
  // dest must already be allocated.
  VW_DLL_PUBLIC VWStatus VWCopyLabel(void*, void*, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWParseLabel(void* label, const char* label_string, VWLabelType, VWErrorString*);

  VW_DLL_PUBLIC VWStatus simple_label_get_label(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus simple_label_set_label(VWSimpleLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus simple_label_get_weight(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus simple_label_set_weight(VWSimpleLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus simple_label_get_initial(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus simple_label_set_initial(VWSimpleLabel*, float, VWErrorString*);

  VW_DLL_PUBLIC VWStatus multiclass_label_get_label(VWMulticlassLabel*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus multiclass_label_set_label(VWMulticlassLabel*, uint32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus multiclass_label_get_weight(VWMulticlassLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus multiclass_label_set_weight(VWMulticlassLabel*, float, VWErrorString*);

  VW_DLL_PUBLIC VWStatus cs_label_get_length(VWCostSensitiveLabel*, int*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cs_label_get_item(VWCostSensitiveLabel*, int index, float* x, uint32_t* class_index,
      float* partial_prediction, float* wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cs_label_set_item(
      VWCostSensitiveLabel*, int index, float x, uint32_t class_index, float partial_prediction, float wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cs_label_push_item(
      VWCostSensitiveLabel*, float x, uint32_t class_index, float partial_prediction, float wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cs_label_remove_item(VWCostSensitiveLabel*, int index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus cb_label_get_length(VWContextualBanditLabel*, int*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_get_weight(VWContextualBanditLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_set_weight(VWContextualBanditLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_get_item(VWContextualBanditLabel*, int index, float* cost, uint32_t* action, float* probability,
      float* partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_set_item(
      VWContextualBanditLabel*, int index, float cost, uint32_t action, float probability, float partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_push_item(
      VWContextualBanditLabel*, float cost, uint32_t action, float probability, float partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_label_remove_item(VWContextualBanditLabel*, int index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus ccb_label_get_type(VWConditionalContextualBanditLabel*, uint8_t* type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_set_type(VWConditionalContextualBanditLabel*, uint8_t type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_get_weight(VWConditionalContextualBanditLabel*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_set_weight(VWConditionalContextualBanditLabel*, float weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_get_explicit_included_actions(
      const VWConditionalContextualBanditLabel*, uint32_t** indices, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_push_explicit_included_actions(VWExample*, uint32_t value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_remove_explicit_included_actions(VWExample*, int index, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_get_labeled(VWSlatesLabel*, bool* labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_set_labeled(VWSlatesLabel*, bool labeled, VWErrorString*);
  // Because of the way CCB labels are structured, using the get following APIs
  // when labeled is false will result in an error and using set will implicitly
  // turn labeled to true
  VW_DLL_PUBLIC VWStatus ccb_label_get_cost(VWSlatesLabel*, float* cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_set_cost(VWSlatesLabel*, float cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_get_length(VWSlatesLabel*, int*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_get_item(VWSlatesLabel*, int index, uint32_t* action, float* score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_set_item(VWSlatesLabel*, int index, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_push_item(VWSlatesLabel*, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus ccb_label_remove_item(VWSlatesLabel*, int index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus slates_label_get_type(VWSlatesLabel*, uint8_t* type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_type(VWSlatesLabel*, uint8_t type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_weight(VWSlatesLabel*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_weight(VWSlatesLabel*, float weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_cost(VWSlatesLabel*, float* cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_cost(VWSlatesLabel*, float cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_labeled(VWSlatesLabel*, bool* labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_labeled(VWSlatesLabel*, bool labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_slot_id(VWSlatesLabel*, uint32_t* slot_id, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_slot_id(VWSlatesLabel*, uint32_t slot_id, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_length(VWSlatesLabel*, int*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_get_item(
      VWSlatesLabel*, int index, uint32_t* action, float* score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_set_item(VWSlatesLabel*, int index, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_push_item(VWSlatesLabel*, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus slates_label_remove_item(VWSlatesLabel*, int index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus cb_eval_label_get_cb_label(VWContexualBanditEvalLabel*, VWContextualBanditLabel* cb_label, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_eval_label_set_cb_label(VWContexualBanditEvalLabel*, VWContextualBanditLabel cb_label, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_eval_label_get_action(VWContexualBanditEvalLabel*, uint32_t* action, VWErrorString*);
  VW_DLL_PUBLIC VWStatus cb_eval_label_set_action(VWContexualBanditEvalLabel*, uint32_t action, VWErrorString*);

  VW_DLL_PUBLIC VWStatus multilabels_label_get(
      VWMultilabelsLabel*, uint32_t** multilabels, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus multilabels_label_push(VWMultilabelsLabel*, uint32_t value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus multilabels_label_remove(VWMultilabelsLabel*, int index, VWErrorString*);

#ifdef __cplusplus
}
#endif
