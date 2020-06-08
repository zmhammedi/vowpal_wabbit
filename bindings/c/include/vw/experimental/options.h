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

  VW_DLL_PUBLIC VWStatus create_options(vw_options**, VWErrorString* err_string);
  VW_DLL_PUBLIC VWStatus create_from_command_line(int argc, char** argv, vw_options**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus create_from_command_line_cstr(const char*, vw_options**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_str(vw_options*, const char* opt_name, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_int32(vw_options*, const char* opt_name, int32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_float(vw_options*, const char* opt_name, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_set_bool(vw_options*, const char* opt_name, bool, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_str(vw_options*, const char* opt_name, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_int32(vw_options*, const char* opt_name, int32_t, VWErrorString*);
  VW_DLL_PUBLIC VWStatus options_list_push_float(vw_options*, const char* opt_name, float, VWErrorString*);
  VW_DLL_PUBLIC VWStatus delete_options(vw_options*, VWErrorString*);

#ifdef __cplusplus
}
#endif
