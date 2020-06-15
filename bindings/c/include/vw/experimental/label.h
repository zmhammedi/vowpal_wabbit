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

  VW_DLL_PUBLIC VWStatus VWCreateLabel(VWLabel**, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDestroyLabel(VWLabel*, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDefaultLabel(VWLabel*, VWLabelType, VWErrorString*);
  // dest must already be allocated.
  VW_DLL_PUBLIC VWStatus VWCopyLabel(VWLabel*, VWLabel*, VWLabelType, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWParseLabel(VWLabel* label, const char* label_string, VWLabelType, VWErrorString*);

  // TODO once initial and weight become part of example this should change.
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetLabel(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetLabel(VWSimpleLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetWeight(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetWeight(VWSimpleLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelGetInitial(VWSimpleLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSimpleLabelSetInitial(VWSimpleLabel*, float, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWMulticlassLabelGetLabel(VWMulticlassLabel*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelSetLabel(VWMulticlassLabel*, uint32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelGetWeight(VWMulticlassLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWMulticlassLabelSetWeight(VWMulticlassLabel*, float, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWCSLabelGetLength(VWCSLabel*, size_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCSLabelGetItem(VWCSLabel*, size_t index, float* x, uint32_t* class_index,
      float* partial_prediction, float* wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCSLabelSetItem(VWCSLabel*, size_t index, float x, uint32_t class_index,
      float partial_prediction, float wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCSLabelPushItem(
      VWCSLabel*, float x, uint32_t class_index, float partial_prediction, float wap_value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCSLabelRemoveItem(VWCSLabel*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWCBLabelGetWeight(VWCBLabel*, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelSetWeight(VWCBLabel*, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelGetLength(VWCBLabel*, size_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelGetItem(VWCBLabel*, size_t index, float* cost, uint32_t* action, float* probability,
      float* partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelSetItem(VWCBLabel*, size_t index, float cost, uint32_t action, float probability,
      float partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelPushItem(
      VWCBLabel*, float cost, uint32_t action, float probability, float partial_prediction, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBLabelRemoveItem(VWCBLabel*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWCCBLabelGetType(VWCCBLabel*, uint8_t* type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetType(VWCCBLabel*, uint8_t type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetWeight(VWCCBLabel*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetWeight(VWCCBLabel*, float weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetExplicitIncludedActions(
      const VWCCBLabel*, uint32_t** indices, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelPushExplicitIncludedAction(VWExample*, uint32_t value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelRemoveExplicitIncludedAction(VWExample*, size_t index, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetLabeled(VWSlatesLabel*, bool* labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetLabeled(VWSlatesLabel*, bool labeled, VWErrorString*);
  // Because of the way CCB labels are structured, using the get following APIs
  // when labeled is false will result in an error and using set will implicitly
  // turn labeled to true
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetCost(VWSlatesLabel*, float* cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetCost(VWSlatesLabel*, float cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetLength(VWSlatesLabel*, size_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelGetItem(
      VWSlatesLabel*, size_t index, uint32_t* action, float* score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelSetItem(VWSlatesLabel*, size_t index, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelPushItem(VWSlatesLabel*, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCCBLabelRemoveItem(VWSlatesLabel*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetType(VWSlatesLabel*, uint8_t* type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetType(VWSlatesLabel*, uint8_t type, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetWeight(VWSlatesLabel*, float* weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetWeight(VWSlatesLabel*, float weight, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetCost(VWSlatesLabel*, float* cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetCost(VWSlatesLabel*, float cost, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetLabeled(VWSlatesLabel*, bool* labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetLabeled(VWSlatesLabel*, bool labeled, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetSlotID(VWSlatesLabel*, uint32_t* slot_id, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetSlotID(VWSlatesLabel*, uint32_t slot_id, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetLength(VWSlatesLabel*, size_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelGetItem(
      VWSlatesLabel*, size_t index, uint32_t* action, float* score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelSetItem(
      VWSlatesLabel*, size_t index, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelPushItem(VWSlatesLabel*, uint32_t action, float score, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSlatesLabelRemoveItem(VWSlatesLabel*, size_t index, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWCBEvalLabelGetVWCBLabel(VWCBEvalLabel*, VWCBLabel* cb_label, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelSetVWCBLabel(VWCBEvalLabel*, VWCBLabel cb_label, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelGetAction(VWCBEvalLabel*, uint32_t* action, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCBEvalLabelSetAction(VWCBEvalLabel*, uint32_t action, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWMultilabelsGetItems(
      VWMultilabelsLabel*, uint32_t** multilabels, size_t* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWMultilabelsPushItem(VWMultilabelsLabel*, uint32_t value, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWMultilabelsRemoveItem(VWMultilabelsLabel*, size_t index, VWErrorString*);

#ifdef __cplusplus
}
#endif
