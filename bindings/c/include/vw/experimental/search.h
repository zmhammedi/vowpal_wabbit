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
  static const uint32_t AUTO_CONDITION_FEATURES = 1;
  static const uint32_t AUTO_HAMMING_LOSS = 2;
  static const uint32_t EXAMPLES_DONT_CHANGE = 4;
  static const uint32_t IS_LDF = 8;

  VW_DLL_PUBLIC VWStatus VWSearchSetOptions(
      VWSearch* search_handle, uint32_t options, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetHistoryLength(
      VWSearch* search_handle, uint32_t* history_length, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchSetLoss(VWSearch* search_handle, float loss, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetShouldOutput(
      VWSearch* search_handle, bool* shouldOutput, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetPredictNeedsExample(
      VWSearch* search_handle, bool* shouldOutput, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchOutput(VWSearch* search_handle, const char* output, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetNumActions(
      VWSearch* search_handle, uint32_t* num_actions, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchSetForceOracle(
      VWSearch* search_handle, bool forceOracle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetIsLDF(VWSearch* search_handle, bool* isLDF, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchGetPredictor(
      VWSearch* search_handle, VWSearchPredictor** predictor, uint32_t ptag, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // This is a rough guess as to what is needed here. We will need to test and update as appropriate.
  typedef VWStatus(VWSearchRunFunc)(void*) VW_API_NOEXCEPT;
  typedef VWStatus(VWSearchSetupFunc)(void*) VW_API_NOEXCEPT;
  typedef VWStatus(VWSearchTeardownFunc)(void*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetPredictHooks(VWSearch* search_handle, VWSearchRunFunc* runFunc,
      void* runContext, VWSearchSetupFunc* setupFunc, void* setupContext, VWSearchTeardownFunc* teardownFunc,
      void* teardownContext, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInput(
      VWSearchPredictor* predictor_handle, VWExample* input, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInputLength(
      VWSearchPredictor* predictor_handle, size_t inputLength, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInputAt(
      VWSearchPredictor* predictor_handle, size_t position, VWExample* input, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushOracle(
      VWSearchPredictor* predictor_handle, uint32_t oracle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearOracle(
      VWSearchPredictor* predictor_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushAllowed(
      VWSearchPredictor* predictor_handle, uint32_t allowed, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearAllowed(
      VWSearchPredictor* predictor_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushCondition(
      VWSearchPredictor* predictor_handle, uint32_t tag, char name, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushConditionRange(
      VWSearchPredictor* predictor_handle, uint32_t hi, uint32_t cout, char name0, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearCondition(
      VWSearchPredictor* predictor_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetLearnerID(
      VWSearchPredictor* predictor_handle, size_t id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetTag(
      VWSearchPredictor* predictor_handle, uint32_t tag, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPredict(
      VWSearchPredictor* predictor_handle, uint32_t* action, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
