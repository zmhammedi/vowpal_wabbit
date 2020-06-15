// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/options.h"

#include "error_handling.h"
#include "interop_helper.h"

#include "options_boost_po.h"
#include "scope_exit.h"
#include "vw.h"

#include <vector>

VW_DLL_PUBLIC VWStatus VWCreateOptions(VWOptions** optionsHandle, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionsHandle, errStrContainer);
  *optionsHandle = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(std::vector<std::string>{}));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLine(
    int argc, char** argv, VWOptions** optionsHandle, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionsHandle, errStrContainer);
  ARG_NOT_NULL(argv, errStrContainer);
  *optionsHandle = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(argc, argv));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLineCString(
    const char* commandLine, VWOptions** optionsHandle, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionsHandle, errStrContainer);
  ARG_NOT_NULL(commandLine, errStrContainer);
  std::string tempString(commandLine);
  int argc = 0;
  char** argv = VW::to_argv_escaped(tempString, argc);
  const auto scope_exit = VW::scope_exit([argc, argv] { VW::free_args(argc, argv); });
  return VWCreateOptionsFromCommandLine(argc, argv, optionsHandle, errStrContainer);
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWDestroyOptions(VWOptions* optionsHandle, VWErrorString* errStrContainer) noexcept
try
{
  auto* options = from_opaque(optionsHandle);
  delete options;
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsSetString(
    VWOptions* optionsHandle, const char* optionName, const char* optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);
  ARG_NOT_NULL(optionValue, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  options->replace(optionName, optionValue);
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsSetInteger(
    VWOptions* optionsHandle, const char* optionName, int32_t optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  options->replace(optionName, std::to_string(optionValue));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsSetFloat(
    VWOptions* optionsHandle, const char* optionName, float optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  options->replace(optionName, std::to_string(optionValue));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsSetBool(
    VWOptions* optionsHandle, const char* optionName, bool optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  // TODO - check if passing true or false works
  options->replace(optionName, optionValue ? "true" : "false");
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsListPushString(
    VWOptions* optionsHandle, const char* optionName, const char* optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);
  ARG_NOT_NULL(optionValue, errStrContainer);
  auto* options = from_opaque(optionsHandle);
  options->insert(optionName, optionValue);
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsListPushInteger(
    VWOptions* optionsHandle, const char* optionName, int32_t optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  options->insert(optionName, std::to_string(optionValue));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)

VW_DLL_PUBLIC VWStatus VWOptionsListPushFloat(
    VWOptions* optionsHandle, const char* optionName, float optionValue, VWErrorString* errStrContainer) noexcept
try
{
  ARG_NOT_NULL(optionName, errStrContainer);

  auto* options = from_opaque(optionsHandle);
  options->insert(optionName, std::to_string(optionValue));
  return VW_SUCCESS;
}
CATCH_RETURN(errStrContainer)