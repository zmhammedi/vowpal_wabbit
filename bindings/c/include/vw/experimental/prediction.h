// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "vw/experimental/vwvis.h"
#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus vw_prediction_as_scalar(
      VWPrediction* prediction, float* scalar, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_prob(VWPrediction* prediction, float* prob, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_scalars(
      VWPrediction* prediction, float* scalars, int* length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_action_scores(
      VWPrediction* prediction, const VWActionScore** action_scores, int length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_action_probs(
      VWPrediction* prediction, const VWActionScore** action_probs, int length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_multiclass(
      VWPrediction* prediction, uint32_t* multiclass, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_multilabels(
      VWPrediction* prediction, const uint32_t** multilabels, int length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_prediction_as_decision_scores(
      VWPrediction* prediction, const VWDecisionScores** decision_scores, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_decision_scores_get_length(
      const VWDecisionScores* prediction, int* length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_decision_scores_get_at(const VWDecisionScores* prediction, int index,
      const VWActionScore** action_scores, int length, VWErrorInfo* err_info_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
