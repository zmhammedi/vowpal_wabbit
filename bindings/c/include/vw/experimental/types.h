
// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <stdint.h>
// ssize_t
#include <sys/types.h>
// bool
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef uint32_t VWStatus;
  static const VWStatus VW_SUCCESS = 0;
  static const VWStatus VW_FAIL = 1;
  static const VWStatus VW_NOT_IMPLEMENTED = 2;
  static const VWStatus VW_INVALID_ARGUMENT = 3;

  typedef uint32_t VWLabelType;
  static const VWLabelType simple = 0;
  static const VWLabelType cb = 1;
  static const VWLabelType cb_eval = 2;
  static const VWLabelType cs = 3;
  static const VWLabelType multi = 4;
  static const VWLabelType mc = 5;
  static const VWLabelType ccb = 6;
  static const VWLabelType slates = 7;

  typedef uint32_t VWPredictionType;
  static const VWPredictionType scalar = 0;
  static const VWPredictionType scalars = 1;
  static const VWPredictionType action_scores = 2;
  static const VWPredictionType action_probs = 3;
  static const VWPredictionType multiclass = 4;
  static const VWPredictionType multilabels = 5;
  static const VWPredictionType prob = 6;
  static const VWPredictionType multiclassprobs = 7;
  static const VWPredictionType decision_probs = 8;

  typedef uint32_t VWHashType;
  static const VWHashType all = 0;
  static const VWHashType text = 1;

  struct VWWorkspace_tag;
  typedef struct VWWorkspace_tag VWWorkspace;

  struct VWErrorString_tag;
  typedef struct VWErrorString_tag VWErrorString;

  struct VWString_tag;
  typedef struct VWString_tag VWString;

  struct VWLabel_tag;
  typedef struct VWLabel_tag VWLabel;

  struct VWPrediction_tag;
  typedef struct VWPrediction_tag VWPrediction;

  struct VWExample_tag;
  typedef struct VWExample_tag VWExample;

  struct VWFeatureSpace_tag;
  typedef struct VWFeatureSpace_tag VWFeatureSpace;

  struct VWDecisionScores_tag;
  typedef struct VWDecisionScores_tag VWDecisionScores;

  struct VWSimpleLabel_tag;
  typedef struct VWSimpleLabel_tag VWSimpleLabel;

  struct VWMulticlassLabel_tag;
  typedef struct VWMulticlassLabel_tag VWMulticlassLabel;

  struct VWCSLabel_tag;
  typedef struct VWCSLabel_tag VWCSLabel;

  struct VWCBLabel_tag;
  typedef struct VWCBLabel_tag VWCBLabel;

  struct VWCCBLabel_tag;
  typedef struct VWCCBLabel_tag VWCCBLabel;

  struct VWSlatesLabel_tag;
  typedef struct VWSlatesLabel_tag VWSlatesLabel;

  struct VWCBEvalLabel_tag;
  typedef struct VWCBEvalLabel_tag VWCBEvalLabel;

  struct VWMultilabelsLabel_tag;
  typedef struct VWMultilabelsLabel_tag VWMultilabelsLabel;

  struct VWWeightIterator_tag;
  typedef struct VWWeightIterator_tag VWWeightIterator;

  struct VWOptions_tag;
  typedef struct VWOptions_tag VWOptions;

  typedef VWStatus(VWReadFunc)(void*, char*, size_t, ssize_t*);
  typedef VWStatus(VWWriteFunc)(void*, const char*, size_t, ssize_t*);
  typedef VWStatus(VWTraceMessageFunc)(void*, int trace_level, const char*, size_t);

  struct VWActionScore_tag
  {
    uint32_t action;
    float score;
  };
  typedef struct VWActionScore_tag VWActionScore;

  struct VWSearch_tag;
  typedef struct VWSearch_tag VWSearch;

  struct VWSearchPredictor_tag;
  typedef struct VWSearchPredictor_tag VWSearchPredictor;

  struct VWHasher_tag;
  typedef struct VWHasher_tag VWHasher;

#ifdef __cplusplus
}
#endif
