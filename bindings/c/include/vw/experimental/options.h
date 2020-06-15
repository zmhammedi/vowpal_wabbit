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

  VW_DLL_PUBLIC VWStatus VWCreateOptions(VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLine(
      int argc, char** argv, VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLineCString(
      const char* commandLine, VWOptions** options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWDestroyOptions(VWOptions* options_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetString(VWOptions* options_handle, const char* option_name,
      const char* option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetInteger(VWOptions* options_handle, const char* option_name, int32_t option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetFloat(VWOptions* options_handle, const char* option_name, float option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetBool(VWOptions* options_handle, const char* option_name, bool option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushString(VWOptions* options_handle, const char* option_name,
      const char* option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushInteger(VWOptions* options_handle, const char* option_name,
      int32_t option_value, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushFloat(VWOptions* options_handle, const char* option_name, float option_value,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
