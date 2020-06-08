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

  VW_DLL_PUBLIC VWStatus VWPredictionAsScalar(void* prediction, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsProb(void* prediction, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsScalars(void* scalars, float*, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsActionScores(void* prediction, const VWActionScore**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsActionProbs(void* prediction, const VWActionScore**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsMulticlass(void* prediction, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsMultilabels(void* prediction, const uint32_t**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWPredictionAsDecisionScores(void* prediction, const VWDecisionScores**, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWDecisionScoresGetLength(const VWDecisionScores* prediction, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDecisionScoresGetAt(VWDecisionScores* prediction, int index, const VWActionScore**, int length, VWErrorString*);

#ifdef __cplusplus
}
#endif
