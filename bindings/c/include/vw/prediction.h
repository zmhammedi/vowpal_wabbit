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

struct c_action_score
{
  uint32_t action;
  float score;
};

vw_status label_scalar(void* label, float*);
vw_status label_prob(void* label, float*);
vw_status label_scalars(void* scalars, float*, int* length);
vw_status label_action_scores(void* label, const c_action_score**, int length);
vw_status label_action_probs(void* label, const c_action_score**, int length);
vw_status label_multiclass(void* label, uint32_t*);
vw_status label_multilabels(void* label, const uint32_t**, int length);
vw_status label_decision_scores(void* label, const vw_decision_scores**);

vw_status decion_scores_length(const vw_decision_scores* label, int* length);
vw_status decion_scores_get(vw_decision_scores* label, int index, const c_action_score**, int length);

#ifdef __cplusplus
}
#endif
