// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

// uint32_t, uint64_t, etc
#include <stdint.h>
// size_t
#include <stddef.h>
// bool
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef uint32_t VWStatus;
  static const VWStatus VW_success = 0;
  // Generate all error codes based on the definitions provided in "error_data.h"
  // This macro gets expanded for each individual error definition
  #define ERROR_CODE_DEFINITION(code, name, message) static const VWStatus VW_##name = code;
  #include "error_data.h"
  #undef ERROR_CODE_DEFINITION

  typedef uint32_t VWLabelType;
  static const VWLabelType VW_LABEL_SIMPLE = 0;
  static const VWLabelType VW_LABEL_CB = 1;
  static const VWLabelType VW_LABEL_CB_EVAL = 2;
  static const VWLabelType VW_LABEL_CS = 3;
  static const VWLabelType VW_LABEL_MULTILABELS = 4;
  static const VWLabelType VW_LABEL_MULTICLASS = 5;
  static const VWLabelType VW_LABEL_CCB = 6;
  static const VWLabelType VW_LABEL_SLATES = 7;

  typedef uint32_t VWPredictionType;
  static const VWPredictionType VW_PRED_SCALAR = 0;
  static const VWPredictionType VW_PRED_SCALARS = 1;
  static const VWPredictionType VW_PRED_ACTION_SCORES = 2;
  static const VWPredictionType VW_PRED_ACTION_PROBS = 3;
  static const VWPredictionType VW_PRED_ACTION_MULTICLASS = 4;
  static const VWPredictionType VW_PRED_ACTION_MULTILABELS = 5;
  static const VWPredictionType VW_PRED_PROB = 6;
  static const VWPredictionType VW_PRED_MUTLICLASS_PROBS = 7;
  static const VWPredictionType VW_PRED_DECISION_PROBS = 8;

  typedef uint32_t VWHashType;
  static const VWHashType all = 0;
  static const VWHashType text = 1;

  typedef uint32_t VWInputType;
  static const VWHashType VW_TEXT_FORMAT = 0;
  static const VWHashType VW_JSON_FORMAT = 1;
  static const VWHashType VW_CACHE_FORMAT = 2;
  // static const VWHashType VW_FLATBUF_FORMAT = 3;

  struct VWWorkspace_tag;
  typedef struct VWWorkspace_tag VWWorkspace;

  struct VWErrorString_tag;
  typedef struct VWErrorString_tag VWErrorInfo;

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

  typedef VWStatus(VWReadFunc)(void*, char*, size_t, size_t*);
  typedef VWStatus(VWWriteFunc)(void*, const char*, size_t, size_t*);
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

  struct VWExampleArrayHolder_tag;
  typedef struct VWExampleArrayHolder_tag VWExampleArrayHolder;

  struct VWAllocator_tag;
  typedef struct VWAllocator_tag VWAllocator;

  typedef VWStatus(VWExampleFactoryFunc)(void*, VWExample**);
  typedef VWStatus(VWExampleCleanupFunc)(void*, VWExample*);

#ifdef __cplusplus
}
#endif
