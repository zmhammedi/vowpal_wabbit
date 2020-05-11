
// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef uint32_t vw_status;
static const vw_status vw_success = 0;
static const vw_status vw_fail = 1;
static const vw_status vw_not_implemented = 2;

struct vw_workspace_tag;
typedef struct vw_workspace_tag vw_workspace;

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

#ifdef __cplusplus
}
#endif

//   typedef void* VW_HANDLE;
//   typedef void* VW_EXAMPLE;
//   typedef void* VW_LABEL;
//   typedef void* VW_FEATURE_SPACE;
//   typedef void* VW_FEATURE;
//   typedef void* VW_IOBUF;