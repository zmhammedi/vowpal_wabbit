
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
  static const VWStatus vw_success = 0;
  static const VWStatus vw_fail = 1;
  static const VWStatus vw_not_implemented = 2;

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

  struct VWCostSensitiveLabel_tag;
  typedef struct VWCostSensitiveLabel_tag VWCostSensitiveLabel;

  struct VWContextualBanditLabel_tag;
  typedef struct VWContextualBanditLabel_tag VWContextualBanditLabel;

  struct VWConditionalContextualBanditLabel_tag;
  typedef struct VWConditionalContextualBanditLabel_tag VWConditionalContextualBanditLabel;

  struct VWSlatesLabel_tag;
  typedef struct VWSlatesLabel_tag VWSlatesLabel;

  struct VWContexualBanditEvalLabel_tag;
  typedef struct VWContexualBanditEvalLabel_tag VWContexualBanditEvalLabel;

  struct VWMultilabelsLabel_tag;
  typedef struct VWMultilabelsLabel_tag VWMultilabelsLabel;

  struct VWWeightIterator_tag;
  typedef struct VWWeightIterator_tag VWWeightIterator;

  struct VWOptions_tag;
  typedef struct VWOptions_tag VWOptions;

  typedef VWStatus(VWReadFunc)(void*, char*, size_t, ssize_t*);
  typedef VWStatus(VWWriteFunc)(void*, const char*, size_t, ssize_t*);
  typedef VWStatus (*VWTraceMessageFunc)(void*, int trace_level, const char*, size_t);

  struct VWActionScore_tag
  {
    uint32_t action;
    float score;
  };
  typedef struct VWActionScore_tag VWActionScore;

#ifdef __cplusplus
}
#endif
