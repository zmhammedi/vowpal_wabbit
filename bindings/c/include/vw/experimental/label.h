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

  VW_DLL_PUBLIC VWStatus vw_create_label(
      VWLabel** label_handle, VWLabelType label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_destroy_label(
      VWLabel* label_handle, VWLabelType label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_default_label(
      VWLabel* label_handle, VWLabelType label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // dest must already be allocated.
  VW_DLL_PUBLIC VWStatus vw_copy_label(VWLabel* dest_label_handle, const VWLabel* source_label_handle, VWLabelType label_type,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_parse_label(
      VWLabel* label_handle, const char* label_string, VWLabelType label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_label_as_simple(
      VWLabel* label_handle, VWSimpleLabel** simple_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_cb(
      VWLabel* label_handle, VWCBLabel** cb_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_cb_eval(
      VWLabel* label_handle, VWCBEvalLabel** cb_eval_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_cs(
      VWLabel* label_handle, VWCSLabel** cs_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_multilabels(
      VWLabel* label_handle, VWMultilabelsLabel** multilabels_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_multiclass(
      VWLabel* label_handle, VWMulticlassLabel** multiclass_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_ccb(
      VWLabel* label_handle, VWCCBLabel** ccb_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_label_as_slates(
      VWLabel* label_handle, VWSlatesLabel** slates_label_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // TODO once initial and weight become part of example this should change.
  VW_DLL_PUBLIC VWStatus vw_simple_label_get_label(
      const VWSimpleLabel* simple_label_handle, float* label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_simple_label_set_label(
      VWSimpleLabel* simple_label_handle, float label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_simple_label_get_weight(
      const VWSimpleLabel* simple_label_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_simple_label_set_weight(
      VWSimpleLabel* simple_label_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_simple_label_get_initial(
      const VWSimpleLabel* simple_label_handle, float* initial, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_simple_label_set_initial(
      VWSimpleLabel* simple_label_handle, float initial, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_cb_label_get_weight(
      VWCBLabel* cb_label_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_set_weight(VWCBLabel* cb_label_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_get_length(
      VWCBLabel* cb_label_handle, size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_get_item(VWCBLabel* cb_label_handle, size_t index, float* cost, uint32_t* action,
      float* probability, float* partial_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_set_item(VWCBLabel* cb_label_handle, size_t index, float cost, uint32_t action,
      float probability, float partial_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_push_item(VWCBLabel* cb_label_handle, float cost, uint32_t action, float probability,
      float partial_prediction, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_label_remove_item(
      VWCBLabel* cb_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_cb_eval_label_get_vw_cb_label(
      VWCBEvalLabel* cb_eval_label_handle, VWCBLabel* cb_label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_eval_label_set_vw_cb_label(
      VWCBEvalLabel* cb_eval_label_handle, VWCBLabel* cb_label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_eval_label_get_action(
      VWCBEvalLabel* cb_eval_label_handle, uint32_t* action, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cb_eval_label_set_action(
      VWCBEvalLabel* cb_eval_label_handle, uint32_t action, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_cs_label_get_length(
      VWCSLabel* cs_label_handle, size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cs_label_get_item(VWCSLabel* cs_label_handle, size_t index, float* x, uint32_t* class_index,
      float* partial_prediction, float* wap_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cs_label_set_item(VWCSLabel* cs_label_handle, size_t index, float x, uint32_t class_index,
      float partial_prediction, float wap_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cs_label_push_item(VWCSLabel* cs_label_handle, float x, uint32_t class_index,
      float partial_prediction, float wap_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_cs_label_remove_item(
      VWCSLabel* cs_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_multilabels_get_items(VWMultilabelsLabel* multilabels_label_handle, uint32_t** multilabels,
      size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_multilabels_push_item(
      VWMultilabelsLabel* multilabels_label_handle, uint32_t value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_multilabels_remove_item(
      VWMultilabelsLabel* multilabels_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_multiclass_label_get_label(
      VWMulticlassLabel* multiclass_label_handle, uint32_t* label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_multiclass_label_set_label(
      VWMulticlassLabel* multiclass_label_handle, uint32_t label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_multiclass_label_get_weight(
      VWMulticlassLabel* multiclass_label_handle, float* label, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_multiclass_label_set_weight(
      VWMulticlassLabel* multiclass_label_handle, float label, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_type(
      VWCCBLabel* ccb_label_handle, uint8_t* type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_set_type(
      VWCCBLabel* ccb_label_handle, uint8_t type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_weight(
      VWCCBLabel* ccb_label_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_set_weight(
      VWCCBLabel* ccb_label_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_explicit_included_actions(
      const VWCCBLabel* ccb_label_handle, uint32_t** indices, int* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_push_explicit_included_action(
      VWCCBLabel* ccb_label_handle, uint32_t value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_remove_explicit_included_action(
      VWCCBLabel* ccb_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_labeled(
      VWCCBLabel* ccb_label_handle, bool* labeled, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_set_labeled(
      VWCCBLabel* ccb_label_handle, bool labeled, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // Because of the way CCB labels are structured, using the get following APIs
  // when labeled is false will result in an error and using set will implicitly
  // turn labeled to true
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_cost(VWCCBLabel* ccb_label_handle, float* cost, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_set_cost(VWCCBLabel* ccb_label_handle, float cost, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_length(
      VWCCBLabel* ccb_label_handle, size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_get_item(
      VWCCBLabel* ccb_label_handle, size_t index, uint32_t* action, float* score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_set_item(
      VWCCBLabel* ccb_label_handle, size_t index, uint32_t action, float score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_push_item(
      VWCCBLabel* ccb_label_handle, uint32_t action, float score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_ccb_label_remove_item(
      VWCCBLabel* ccb_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_slates_label_get_type(
      VWSlatesLabel* slates_label_handle, uint8_t* type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_type(
      VWSlatesLabel* slates_label_handle, uint8_t type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_weight(
      VWSlatesLabel* slates_label_handle, float* weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_weight(
      VWSlatesLabel* slates_label_handle, float weight, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_cost(
      VWSlatesLabel* slates_label_handle, float* cost, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_cost(
      VWSlatesLabel* slates_label_handle, float cost, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_labeled(
      VWSlatesLabel* slates_label_handle, bool* labeled, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_labeled(
      VWSlatesLabel* slates_label_handle, bool labeled, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_slot_id(
      VWSlatesLabel* slates_label_handle, uint32_t* slot_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_slot_id(
      VWSlatesLabel* slates_label_handle, uint32_t slot_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_length(
      VWSlatesLabel* slates_label_handle, size_t* length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_get_item(VWSlatesLabel* slates_label_handle, size_t index, uint32_t* action,
      float* score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_set_item(
      VWSlatesLabel* slates_label_handle, size_t index, uint32_t action, float score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_push_item(
      VWSlatesLabel* slates_label_handle, uint32_t action, float score, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_slates_label_remove_item(
      VWSlatesLabel* slates_label_handle, size_t index, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
