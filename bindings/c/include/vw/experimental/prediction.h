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

  VW_DLL_PUBLIC VWStatus prediction_scalar(void* prediction, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_prob(void* prediction, float*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_scalars(void* scalars, float*, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_action_scores(void* prediction, const VWActionScore**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_action_probs(void* prediction, const VWActionScore**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_multiclass(void* prediction, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_multilabels(void* prediction, const uint32_t**, int length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus prediction_decision_scores(void* prediction, const VWDecisionScores**, VWErrorString*);

  VW_DLL_PUBLIC VWStatus decision_scores_length(const VWDecisionScores* prediction, int* length, VWErrorString*);
  VW_DLL_PUBLIC VWStatus decision_scores_get(VWDecisionScores* prediction, int index, const VWActionScore**, int length, VWErrorString*);

#ifdef __cplusplus
}
#endif
