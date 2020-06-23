// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include "vw/experimental/types.h"

#include "owned_string.h"
#include "allocator.h"
#include "hasher.h"

#include "vw.h"

#define FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)                                       \
  inline CPP_TYPE* from_opaque(C_TYPE* ptr) { return reinterpret_cast<CPP_TYPE*>(ptr); } \
  inline const CPP_TYPE* from_opaque(const C_TYPE* ptr) { return reinterpret_cast<const CPP_TYPE*>(ptr); }

#define TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)                                     \
  inline C_TYPE* to_opaque(CPP_TYPE* ptr) { return reinterpret_cast<C_TYPE*>(ptr); } \
  inline const C_TYPE* to_opaque(const CPP_TYPE* ptr) { return reinterpret_cast<const C_TYPE*>(ptr); }

#define TO_FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE) \
  FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)          \
  TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)

// Does not support to_opaque because owned_string can be either VWErrorString* or VWString*
FROM_OPAQUE_FUNCS(VWErrorString, owned_string);
FROM_OPAQUE_FUNCS(VWString, owned_string);
FROM_OPAQUE_FUNCS(VWOptions, VW::config::options_i);

TO_FROM_OPAQUE_FUNCS(VWWorkspace, vw);
TO_FROM_OPAQUE_FUNCS(VWExample, example);
TO_FROM_OPAQUE_FUNCS(VWAllocator, vw_allocator);
TO_FROM_OPAQUE_FUNCS(VWFeatureSpace, features);
TO_FROM_OPAQUE_FUNCS(VWHasher, vw_hasher);

#define PRED_CASE(internal_type, c_type) \
  case internal_type:                    \
    return c_type;

inline VWPredictionType internal_to_c_enum(prediction_type_t internal_type)
{
  switch (internal_type)
  {
    PRED_CASE(prediction_type_t::scalar, VW_PRED_SCALAR);
    PRED_CASE(prediction_type_t::scalars, VW_PRED_SCALARS);
    PRED_CASE(prediction_type_t::action_scores, VW_PRED_ACTION_SCORES);
    PRED_CASE(prediction_type_t::action_probs, VW_PRED_ACTION_PROBS);
    PRED_CASE(prediction_type_t::multiclass, VW_PRED_ACTION_MULTICLASS);
    PRED_CASE(prediction_type_t::multilabels, VW_PRED_ACTION_MULTILABELS);
    PRED_CASE(prediction_type_t::prob, VW_PRED_PROB);
    PRED_CASE(prediction_type_t::multiclassprobs, VW_PRED_MUTLICLASS_PROBS);
    PRED_CASE(prediction_type_t::decision_probs, VW_PRED_DECISION_PROBS);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

inline prediction_type_t c_to_internal_enum_pred(VWPredictionType c_type)
{
  switch (c_type)
  {
    PRED_CASE(VW_PRED_SCALAR, prediction_type_t::scalar);
    PRED_CASE(VW_PRED_SCALARS, prediction_type_t::scalars);
    PRED_CASE(VW_PRED_ACTION_SCORES, prediction_type_t::action_scores);
    PRED_CASE(VW_PRED_ACTION_PROBS, prediction_type_t::action_probs);
    PRED_CASE(VW_PRED_ACTION_MULTICLASS, prediction_type_t::multiclass);
    PRED_CASE(VW_PRED_ACTION_MULTILABELS, prediction_type_t::multilabels);
    PRED_CASE(VW_PRED_PROB, prediction_type_t::prob);
    PRED_CASE(VW_PRED_MUTLICLASS_PROBS, prediction_type_t::multiclassprobs);
    PRED_CASE(VW_PRED_DECISION_PROBS, prediction_type_t::decision_probs);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

inline VWLabelType internal_to_c_enum(label_type_t internal_type)
{
  switch (internal_type)
  {
    PRED_CASE(label_type_t::simple, VW_LABEL_SIMPLE);
    PRED_CASE(label_type_t::cb, VW_LABEL_CB);
    PRED_CASE(label_type_t::cb_eval, VW_LABEL_CB_EVAL);
    PRED_CASE(label_type_t::cs, VW_LABEL_CS);
    PRED_CASE(label_type_t::multi, VW_LABEL_MULTILABELS);
    PRED_CASE(label_type_t::mc, VW_LABEL_MULTICLASS);
    PRED_CASE(label_type_t::ccb, VW_LABEL_CCB);
    PRED_CASE(label_type_t::slates, VW_LABEL_SLATES);
    default:
      THROW("Unknown label type. Cannot convert.");
  }
}

inline label_type_t c_to_internal_enum_label(VWLabelType c_type)
{
  switch (c_type)
  {
    PRED_CASE(VW_LABEL_SIMPLE, label_type_t::simple);
    PRED_CASE(VW_LABEL_CB, label_type_t::cb);
    PRED_CASE(VW_LABEL_CB_EVAL, label_type_t::cb_eval);
    PRED_CASE(VW_LABEL_CS, label_type_t::cs);
    PRED_CASE(VW_LABEL_MULTILABELS, label_type_t::multi);
    PRED_CASE(VW_LABEL_MULTICLASS, label_type_t::mc);
    PRED_CASE(VW_LABEL_CCB, label_type_t::ccb);
    PRED_CASE(VW_LABEL_SLATES, label_type_t::slates);
    default:
      THROW("Unknown prediction type. Cannot convert.");
  }
}

#undef PRED_CASE
