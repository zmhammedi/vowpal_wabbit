// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/prediction.h"

#include "error_handling.h"

VW_DLL_PUBLIC VWStatus vw_prediction_as_scalar(
    VWPrediction* prediction, float* scalar, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_prob(
    VWPrediction* prediction, float* prob, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_scalars(
    VWPrediction* prediction, float* scalars, int* length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_action_scores(VWPrediction* prediction, const VWActionScore** action_scores,
    int length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_action_probs(
    VWPrediction* prediction, const VWActionScore** action_probs, int length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_multiclass(
    VWPrediction* prediction, uint32_t* multiclass, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_multilabels(
    VWPrediction* prediction, const uint32_t** multilabels, int length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_prediction_as_decision_scores(
    VWPrediction* prediction, const VWDecisionScores** decision_scores, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_decision_scores_get_length(
    const VWDecisionScores* prediction, int* length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_decision_scores_get_at(const VWDecisionScores* prediction, int index,
    const VWActionScore** action_scores, int length, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)
