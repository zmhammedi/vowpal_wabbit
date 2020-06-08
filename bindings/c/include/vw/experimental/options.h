// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

  VW_DLL_PUBLIC VWStatus create_options(VWOptions**, VWErrorString* err_string);
  VW_DLL_PUBLIC VWStatus create_from_command_line(int argc, char** argv, VWOptions**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus create_from_command_line_cstr(const char*, VWOptions**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_str(VWOptions*, const char* opt_name, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_int32(VWOptions*, const char* opt_name, int32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_float(VWOptions*, const char* opt_name, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_bool(VWOptions*, const char* opt_name, bool, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_str(VWOptions*, const char* opt_name, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_int32(VWOptions*, const char* opt_name, int32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_float(VWOptions*, const char* opt_name, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus delete_options(VWOptions*, VWErrorString*);

#ifdef __cplusplus
}
#endif
