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

typedef uint32_t vw_label_type;
static const vw_label_type vw_label_simple = 0;

vw_status label_allocate(vw_label** label, void* ss, vw_label_type type);
vw_status label_deallocate(vw_label* label);

vw_status label_set(vw_label* label, void* ss, vw_label_type type);
vw_status label_get_value(vw_label* label, void** example);
vw_status label_get_type(vw_label* label, vw_label_type* type);

#ifdef __cplusplus
}
#endif
