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

  // might return a multiline example in the case of the json parser
  vw_status read_example(vw_workspace*, const char* line, vw_example**, size_t*);

#ifdef __cplusplus
}
#endif
