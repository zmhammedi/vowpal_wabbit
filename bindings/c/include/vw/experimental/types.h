
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

  typedef uint32_t vw_label_type;
  static const vw_label_type simple = 0;
  static const vw_label_type cb = 1;
  static const vw_label_type cb_eval = 2;
  static const vw_label_type cs = 3;
  static const vw_label_type multi = 4;
  static const vw_label_type mc = 5;
  static const vw_label_type ccb = 6;
  static const vw_label_type slates = 7;

  typedef uint32_t vw_prediction_type;
  static const vw_prediction_type scalar = 0;
  static const vw_prediction_type scalars = 1;
  static const vw_prediction_type action_scores = 2;
  static const vw_prediction_type action_probs = 3;
  static const vw_prediction_type multiclass = 4;
  static const vw_prediction_type multilabels = 5;
  static const vw_prediction_type prob = 6;
  static const vw_prediction_type multiclassprobs = 7;
  static const vw_prediction_type decision_probs = 8;

  typedef uint32_t vw_hash_type;
  static const vw_hash_type all = 0;
  static const vw_hash_type text = 1;

  struct VWWorkspace_tag;
  typedef struct VWWorkspace_tag VWWorkspace;

  struct VWErrorString_tag;
  typedef struct VWErrorString_tag VWErrorString;

  struct vw_str_tag;
  typedef struct vw_str_tag vw_str;

  struct vw_label_tag;
  typedef struct vw_label_tag vw_label;

  struct vw_prediction_tag;
  typedef struct vw_prediction_tag vw_prediction;

  struct vw_example_tag;
  typedef struct vw_example_tag vw_example;

  struct vw_interactions_tag;
  typedef struct vw_interactions_tag vw_interactions;

  struct vw_feature_space_tag;
  typedef struct vw_feature_space_tag vw_feature_space;

  struct vw_feature_space_ref_tag;
  typedef struct vw_feature_space_ref_tag vw_feature_space_ref;

  struct vw_decision_scores_tag;
  typedef struct vw_decision_scores_tag vw_decision_scores;

  struct vw_simple_label_tag;
  typedef struct vw_simple_label_tag vw_simple_label;

  struct vw_multiclass_label_tag;
  typedef struct vw_multiclass_label_tag vw_multiclass_label;

  struct vw_cs_label_tag;
  typedef struct vw_cs_label_tag vw_cs_label;

  struct vw_cb_label_tag;
  typedef struct vw_cb_label_tag vw_cb_label;

  struct vw_ccb_label_tag;
  typedef struct vw_ccb_label_tag vw_ccb_label;

  struct vw_ccb_outcome_tag;
  typedef struct vw_ccb_outcome_tag vw_ccb_outcome;

  struct vw_slates_label_tag;
  typedef struct vw_slates_label_tag vw_slates_label;

  struct vw_cb_eval_label_tag;
  typedef struct vw_cb_eval_label_tag vw_cb_eval_label;

  struct vw_multilabels_label_tag;
  typedef struct vw_multilabels_label_tag vw_multilabels_label;

  struct vw_weight_iter_tag;
  typedef struct vw_weight_iter_tag vw_weight_iter;

  struct vw_options_tag;
  typedef struct vw_options_tag vw_options;

  typedef VWStatus(read_func)(void*, char*, size_t, ssize_t*);
  typedef VWStatus(write_func)(void*, const char*, size_t, ssize_t*);
  typedef VWStatus (*trace_message_func)(void*, int trace_level, const char*, size_t);

  struct c_action_score_tag
  {
    uint32_t action;
    float score;
  };
  typedef struct c_action_score_tag c_action_score;

#ifdef __cplusplus
}
#endif
