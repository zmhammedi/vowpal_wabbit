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

  // Start the parser+driver loops
  VW_DLL_PUBLIC VWStatus VWRunParserAndDriver(VWWorkspace*, VWErrorString*);

  // might return a multiline example in the case of the json parser
  VW_DLL_PUBLIC VWStatus VWParseExample(VWWorkspace*, const char* line, VWExample**, size_t*, VWErrorString*);

#ifdef __cplusplus
}
#endif
