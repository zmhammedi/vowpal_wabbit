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

  VW_DLL_PUBLIC VWStatus VWCreateOptions(VWOptions** optionsHandle, VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLine(
      int argc, char** argv, VWOptions** optionsHandle, VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLineCString(
      const char* commandLine, VWOptions** optionsHandle, VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWDestroyOptions(VWOptions* optionsHandle, VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetString(VWOptions* optionsHandle, const char* optionName, const char* optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetInteger(VWOptions* optionsHandle, const char* optionName, int32_t optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetFloat(VWOptions* optionsHandle, const char* optionName, float optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsSetBool(VWOptions* optionsHandle, const char* optionName, bool optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushString(VWOptions* optionsHandle, const char* optionName,
      const char* optionValue, VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushInteger(VWOptions* optionsHandle, const char* optionName, int32_t optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWOptionsListPushFloat(VWOptions* optionsHandle, const char* optionName, float optionValue,
      VWErrorString* errStrContainer) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
