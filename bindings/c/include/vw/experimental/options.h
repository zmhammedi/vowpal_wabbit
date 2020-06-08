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

  VW_DLL_PUBLIC vw_status create_options(vw_options**, vw_err_str* err_string);
  VW_DLL_PUBLIC vw_status create_from_command_line(int argc, char** argv, vw_options**, vw_err_str*);
  VW_DLL_PUBLIC vw_status create_from_command_line_cstr(const char*, vw_options**, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_str(vw_options*, const char* opt_name, const char*, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_int32(vw_options*, const char* opt_name, int32_t, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_float(vw_options*, const char* opt_name, float, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_bool(vw_options*, const char* opt_name, bool, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_str(vw_options*, const char* opt_name, const char*, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_int32(vw_options*, const char* opt_name, int32_t, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_float(vw_options*, const char* opt_name, float, vw_err_str*);
  VW_DLL_PUBLIC vw_status delete_options(vw_options*, vw_err_str*);

#ifdef __cplusplus
}
#endif
