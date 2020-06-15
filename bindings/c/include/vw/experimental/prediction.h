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

  VW_DLL_PUBLIC VWStatus VWPredictionAsScalar(
      VWPrediction* prediction, float* scalar, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsProb(VWPrediction* prediction, float* prob, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsScalars(
      VWPrediction* prediction, float* scalars, int* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsActionScores(
      VWPrediction* prediction, const VWActionScore** action_scores, int length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsActionProbs(
      VWPrediction* prediction, const VWActionScore** action_probs, int length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsMulticlass(
      VWPrediction* prediction, uint32_t* multiclass, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsMultilabels(
      VWPrediction* prediction, const uint32_t** multilabels, int length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWPredictionAsDecisionScores(
      VWPrediction* prediction, const VWDecisionScores** decision_scores, VWErrorString* err_str_container);

  VW_DLL_PUBLIC VWStatus VWDecisionScoresGetLength(
      const VWDecisionScores* prediction, int* length, VWErrorString* err_str_container);
  VW_DLL_PUBLIC VWStatus VWDecisionScoresGetAt(const VWDecisionScores* prediction, int index,
      const VWActionScore** action_scores, int length, VWErrorString* err_str_container);

#ifdef __cplusplus
}
#endif
