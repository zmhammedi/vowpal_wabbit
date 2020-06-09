// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif
  static const uint32_t AUTO_CONDITION_FEATURES = 1;
  static const uint32_t AUTO_HAMMING_LOSS = 2;
  static const uint32_t EXAMPLES_DONT_CHANGE = 4;
  static const uint32_t IS_LDF = 8;

  VW_DLL_PUBLIC VWStatus VWSearchSetOptions(VWSearch*, uint32_t options, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetHistoryLength(VWSearch*, uint32_t* history_length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchSetLoss(VWSearch*, float loss, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetShouldOutput(VWSearch*, bool* shouldOutput, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetPredictNeedsExample(VWSearch*, bool* shouldOutput, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchOutput(VWSearch*, const char* output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetNumActions(VWSearch*, uint32_t* num_actions, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchSetForceOracle(VWSearch*, bool forceOracle, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetIsLDF(VWSearch*, bool* isLDF, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchGetPredictor(VWSearch*, VWSearchPredictor** predictor, uint32_t ptag, VWErrorString*);

  // This is a rough guess as to what is needed here. We will need to test and update as appropriate.
  typedef VWStatus(VWSearchRunFunc)(void*);
  typedef VWStatus(VWSearchSetupFunc)(void*);
  typedef VWStatus(VWSearchTeardownFunc)(void*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetPredictHooks(VWSearch*, VWSearchRunFunc* runFunc, void* runContext,
      VWSearchSetupFunc* setupFunc, void* setupContext, VWSearchTeardownFunc* teardownFunc, void* teardownContext,
      VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInput(VWSearch*, VWExample* input, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInputLength(VWSearch*, size_t inputLength, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetInputAt(VWSearch*, size_t position, VWExample* input, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushOracle(VWSearch*, uint32_t oracle, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearOracle(VWSearch*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushAllowed(VWSearch*, uint32_t allowed, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearAllowed(VWSearch*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushCondition(VWSearch*, uint32_t tag, char name, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPushConditionRange(
      VWSearch*, uint32_t hi, uint32_t cout, char name0, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorClearCondition(VWSearch*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetLearnerID(VWSearch*, size_t id, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorSetTag(VWSearch*, uint32_t tag, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSearchPredictorPredict(VWSearch*, uint32_t* action, VWErrorString*);

#ifdef __cplusplus
}
#endif
