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

  VW_DLL_PUBLIC VWStatus vw_create_options(VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_create_options_from_command_line(
      int argc, char** argv, VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_create_options_from_command_line_c_string(
      const char* commandLine, VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_destroy_options(VWOptions* options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_set_string(VWOptions* options_handle, const char* option_name,
      const char* option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_set_integer(VWOptions* options_handle, const char* option_name, int32_t option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_set_float(VWOptions* options_handle, const char* option_name, float option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_set_bool(VWOptions* options_handle, const char* option_name, bool option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_list_push_string(VWOptions* options_handle, const char* option_name,
      const char* option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_list_push_integer(VWOptions* options_handle, const char* option_name,
      int32_t option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_options_list_push_float(VWOptions* options_handle, const char* option_name, float option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
