// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/options.h"

#include "vw_error_string.h"
#include "error_handling.h"

#include "options_boost_po.h"
#include "scope_exit.h"
#include "vw.h"
#include "vw_exception.h"

#include <vector>

VW_DLL_PUBLIC VWStatus VWCreateOptions(VWOptions** options, VWErrorString* errorString) noexcept
try
{
  *options = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(std::vector<std::string>{}));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLine(
    int argc, char** argv, VWOptions** options, VWErrorString* errorString) noexcept
try
{
  *options = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(argc, argv));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLineCString(
    const char* commandLine, VWOptions** options, VWErrorString* errorString) noexcept
try
{
  std::string tempString(commandLine);
  int argc = 0;
  char** argv = VW::to_argv_escaped(tempString, argc);
  const auto scope_exit = VW::scope_exit([argc, argv] { VW::free_args(argc, argv); });
  return VWCreateOptionsFromCommandLine(argc, argv, options, errorString);
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWDestroyOptions(VWOptions* options, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  delete options_i;
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsSetString(
    VWOptions* options, const char* option_name, const char* option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->replace(option_name, option_value);
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsSetInteger(
    VWOptions* options, const char* option_name, int32_t option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->replace(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsSetFloat(
    VWOptions* options, const char* option_name, float option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->replace(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsSetBool(
    VWOptions* options, const char* option_name, bool option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  // TODO - check if passing true or false works
  options_i->replace(option_name, option_value ? "true" : "false");
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsListPushString(
    VWOptions* options, const char* option_name, const char* option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->insert(option_name, option_value);
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsListPushInteger(
    VWOptions* options, const char* option_name, int32_t option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->insert(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)

VW_DLL_PUBLIC VWStatus VWOptionsListPushFloat(
    VWOptions* options, const char* option_name, float option_value, VWErrorString* errorString) noexcept
try
{
  auto* options_i = reinterpret_cast<VW::config::options_i*>(options);
  options_i->insert(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(errorString)
