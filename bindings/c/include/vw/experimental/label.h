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

  VW_DLL_PUBLIC VWStatus VWCreateLabel(
      VWLabel** label_handle, VWLabelType label_type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWDestroyLabel(
      VWLabel* label_handle, VWLabelType label_type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWDefaultLabel(
      VWLabel* label_handle, VWLabelType label_type, VWErrorString* err_str_container);
  // dest must already be allocated.
  VW_DLL_PUBLIC VWStatus VWCopyLabel(VWLabel* dest_label_handle, VWLabel* source_label_handle, VWLabelType label_type,
      VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWParseLabel(
      VWLabel* label_handle, const char* label_string, VWLabelType label_type, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWLabelAsSimple(
      VWLabel* label_handle, VWSimpleLabel** simple_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsCB(
      VWLabel* label_handle, VWCBLabel** cb_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsCBEval(
      VWLabel* label_handle, VWCBEvalLabel** cb_eval_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsCS(
      VWLabel* label_handle, VWCSLabel** cs_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsMultilabels(
      VWLabel* label_handle, VWMultilabelsLabel** multilabels_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsMulticlass(
      VWLabel* label_handle, VWMulticlassLabel** multiclass_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsCCB(
      VWLabel* label_handle, VWCCBLabel** ccb_label_handle, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWLabelAsSlates(
      VWLabel* label_handle, VWSlatesLabel** slates_label_handle, VWErrorString* err_str_container);

  // TODO once initial and weight become part of example this should change.
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetLabel(
      VWSimpleLabel* simple_label_handle, float* label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetLabel(
      VWSimpleLabel* simple_label_handle, float label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetWeight(
      VWSimpleLabel* simple_label_handle, float* weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetWeight(
      VWSimpleLabel* simple_label_handle, float weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetInitial(
      VWSimpleLabel* simple_label_handle, float* initial, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetInitial(
      VWSimpleLabel* simple_label_handle, float initial, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWCBLabelGetWeight(
      VWCBLabel* cb_label_handle, float* weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelSetWeight(VWCBLabel* cb_label_handle, float weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelGetLength(
      VWCBLabel* cb_label_handle, size_t* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelGetItem(VWCBLabel* cb_label_handle, size_t index, float* cost, uint32_t* action,
      float* probability, float* partial_prediction, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelSetItem(VWCBLabel* cb_label_handle, size_t index, float cost, uint32_t action,
      float probability, float partial_prediction, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelPushItem(VWCBLabel* cb_label_handle, float cost, uint32_t action, float probability,
      float partial_prediction, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBLabelRemoveItem(
      VWCBLabel* cb_label_handle, size_t index, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWCBEvalLabelGetVWCBLabel(
      VWCBEvalLabel* cb_eval_label_handle, VWCBLabel* cb_label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelSetVWCBLabel(
      VWCBEvalLabel* cb_eval_label_handle, VWCBLabel cb_label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelGetAction(
      VWCBEvalLabel* cb_eval_label_handle, uint32_t* action, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelSetAction(
      VWCBEvalLabel* cb_eval_label_handle, uint32_t action, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWCSLabelGetLength(
      VWCSLabel* cs_label_handle, size_t* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCSLabelGetItem(VWCSLabel* cs_label_handle, size_t index, float* x, uint32_t* class_index,
      float* partial_prediction, float* wap_value, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCSLabelSetItem(VWCSLabel* cs_label_handle, size_t index, float x, uint32_t class_index,
      float partial_prediction, float wap_value, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCSLabelPushItem(VWCSLabel* cs_label_handle, float x, uint32_t class_index,
      float partial_prediction, float wap_value, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCSLabelRemoveItem(
      VWCSLabel* cs_label_handle, size_t index, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWMultilabelsGetItems(VWMultilabelsLabel* multilabels_label_handle, uint32_t** multilabels,
      size_t* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWMultilabelsPushItem(
      VWMultilabelsLabel* multilabels_label_handle, uint32_t value, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWMultilabelsRemoveItem(
      VWMultilabelsLabel* multilabels_label_handle, size_t index, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWMulticlassLabelGetLabel(
      VWMulticlassLabel* multiclass_label_handle, uint32_t* label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelSetLabel(
      VWMulticlassLabel* multiclass_label_handle, uint32_t label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelGetWeight(
      VWMulticlassLabel* multiclass_label_handle, float* label, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelSetWeight(
      VWMulticlassLabel* multiclass_label_handle, float label, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWCCBLabelGetType(
      VWCCBLabel* ccb_label_handle, uint8_t* type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetType(
      VWCCBLabel* ccb_label_handle, uint8_t type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetWeight(
      VWCCBLabel* ccb_label_handle, float* weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetWeight(
      VWCCBLabel* ccb_label_handle, float weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetExplicitIncludedActions(
      const VWCCBLabel* ccb_label_handle, uint32_t** indices, int* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelPushExplicitIncludedAction(
      VWCCBLabel* ccb_label_handle, uint32_t value, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelRemoveExplicitIncludedAction(
      VWCCBLabel* ccb_label_handle, size_t index, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetLabeled(
      VWCCBLabel* ccb_label_handle, bool* labeled, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetLabeled(
      VWCCBLabel* ccb_label_handle, bool labeled, VWErrorString* err_str_container);
  // Because of the way CCB labels are structured, using the get following APIs
  // when labeled is false will result in an error and using set will implicitly
  // turn labeled to true
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetCost(VWCCBLabel* ccb_label_handle, float* cost, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetCost(VWCCBLabel* ccb_label_handle, float cost, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetLength(
      VWCCBLabel* ccb_label_handle, size_t* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetItem(
      VWCCBLabel* ccb_label_handle, size_t index, uint32_t* action, float* score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetItem(
      VWCCBLabel* ccb_label_handle, size_t index, uint32_t action, float score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelPushItem(
      VWCCBLabel* ccb_label_handle, uint32_t action, float score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWCCBLabelRemoveItem(
      VWCCBLabel* ccb_label_handle, size_t index, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetType(
      VWSlatesLabel* slates_label_handle, uint8_t* type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetType(
      VWSlatesLabel* slates_label_handle, uint8_t type, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetWeight(
      VWSlatesLabel* slates_label_handle, float* weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetWeight(
      VWSlatesLabel* slates_label_handle, float weight, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetCost(
      VWSlatesLabel* slates_label_handle, float* cost, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetCost(
      VWSlatesLabel* slates_label_handle, float cost, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetLabeled(
      VWSlatesLabel* slates_label_handle, bool* labeled, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetLabeled(
      VWSlatesLabel* slates_label_handle, bool labeled, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetSlotID(
      VWSlatesLabel* slates_label_handle, uint32_t* slot_id, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetSlotID(
      VWSlatesLabel* slates_label_handle, uint32_t slot_id, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetLength(
      VWSlatesLabel* slates_label_handle, size_t* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetItem(VWSlatesLabel* slates_label_handle, size_t index, uint32_t* action,
      float* score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetItem(
      VWSlatesLabel* slates_label_handle, size_t index, uint32_t action, float score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelPushItem(
      VWSlatesLabel* slates_label_handle, uint32_t action, float score, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelRemoveItem(
      VWSlatesLabel* slates_label_handle, size_t index, VWErrorString* err_str_container);

#ifdef __cplusplus
}
#endif
