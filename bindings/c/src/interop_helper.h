// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include "vw/experimental/types.h"

#include "owned_string.h"

#include "vw.h"

#define FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)                                       \
  CPP_TYPE* from_opaque(C_TYPE* ptr) { return reinterpret_cast<CPP_TYPE*>(ptr); } \
  const CPP_TYPE* from_opaque(const C_TYPE* ptr) { return reinterpret_cast<const CPP_TYPE*>(ptr); }

#define TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)                                     \
  C_TYPE* to_opaque(CPP_TYPE* ptr) { return reinterpret_cast<C_TYPE*>(ptr); } \
  const C_TYPE* to_opaque(const CPP_TYPE* ptr) { return reinterpret_cast<const C_TYPE*>(ptr); }

#define TO_FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE) \
  FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)          \
  TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)

// Does not support to_opaque because owned_string can be either VWErrorString* or VWString*
FROM_OPAQUE_FUNCS(VWErrorString, owned_string);
FROM_OPAQUE_FUNCS(VWString, owned_string);
FROM_OPAQUE_FUNCS(VWOptions, VW::config::options_i);

TO_FROM_OPAQUE_FUNCS(VWWorkspace, vw);
TO_FROM_OPAQUE_FUNCS(VWExample, example);

#define PRED_CASE(internal_type, c_type) \
  case internal_type:                    \
    return c_type;

VWPredictionType internal_to_c_enum(prediction_type_t internal_type)
{
  switch (internal_type)
  {
    PRED_CASE(prediction_type_t::scalar, VWPredictionScalar);
    PRED_CASE(prediction_type_t::scalars, VWPredictionScalars);
    PRED_CASE(prediction_type_t::action_scores, VWPredictionActionScores);
    PRED_CASE(prediction_type_t::action_probs, VWPredictionActionProbs);
    PRED_CASE(prediction_type_t::multiclass, VWPredictionMulticlass);
    PRED_CASE(prediction_type_t::multilabels, VWPredictionMultiLabels);
    PRED_CASE(prediction_type_t::prob, VWPredictionProb);
    PRED_CASE(prediction_type_t::multiclassprobs, VWPredictionMulticlassProbs);
    PRED_CASE(prediction_type_t::decision_probs, VWPredictionDecisionProbs);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

prediction_type_t c_to_internal_enum(VWPredictionType c_type)
{
  switch (c_type)
  {
    PRED_CASE(VWPredictionScalar, prediction_type_t::scalar);
    PRED_CASE(VWPredictionScalars, prediction_type_t::scalars);
    PRED_CASE(VWPredictionActionScores, prediction_type_t::action_scores);
    PRED_CASE(VWPredictionActionProbs, prediction_type_t::action_probs);
    PRED_CASE(VWPredictionMulticlass, prediction_type_t::multiclass);
    PRED_CASE(VWPredictionMultiLabels, prediction_type_t::multilabels);
    PRED_CASE(VWPredictionProb, prediction_type_t::prob);
    PRED_CASE(VWPredictionMulticlassProbs, prediction_type_t::multiclassprobs);
    PRED_CASE(VWPredictionDecisionProbs, prediction_type_t::decision_probs);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

VWLabelType internal_to_c_enum(label_type_t internal_type)
{
  switch (internal_type)
  {
    PRED_CASE(label_type_t::simple, VWLabelSimple);
    PRED_CASE(label_type_t::cb, VWLabelCB);
    PRED_CASE(label_type_t::cb_eval, VWLabelCBEval);
    PRED_CASE(label_type_t::cs, VWLabelCS);
    PRED_CASE(label_type_t::mc, VWLabelMC);
    PRED_CASE(label_type_t::ccb, VWLabelCCB);
    PRED_CASE(label_type_t::slates, VWLabelSlates);
    default:
      THROW("Unknown label type. Cannot convert.");
  }
}

VWPredictionType c_to_internal_enum(prediction_type_t c_type)
{
  switch (c_type)
  {
    PRED_CASE(prediction_type_t::scalar, VWPredictionScalar);
    PRED_CASE(prediction_type_t::scalars, VWPredictionScalars);
    PRED_CASE(prediction_type_t::action_scores, VWPredictionActionScores);
    PRED_CASE(prediction_type_t::action_probs, VWPredictionActionProbs);
    PRED_CASE(prediction_type_t::multiclass, VWPredictionMulticlass);
    PRED_CASE(prediction_type_t::multilabels, VWPredictionMultiLabels);
    PRED_CASE(prediction_type_t::prob, VWPredictionProb);
    PRED_CASE(prediction_type_t::multiclassprobs, VWPredictionMulticlassProbs);
    PRED_CASE(prediction_type_t::decision_probs, VWPredictionDecisionProbs);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

#undef PRED_CASE
