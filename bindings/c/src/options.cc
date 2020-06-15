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

VW_DLL_PUBLIC VWStatus VWCreateOptions(VWOptions** options_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(options_handle, err_str_container);
  *options_handle = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(std::vector<std::string>{}));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLine(
    int argc, char** argv, VWOptions** options_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(options_handle, err_str_container);
  ARG_NOT_NULL(argv, err_str_container);
  *options_handle = reinterpret_cast<VWOptions*>(new VW::config::options_boost_po(argc, argv));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWCreateOptionsFromCommandLineCString(
    const char* commandLine, VWOptions** options_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(options_handle, err_str_container);
  ARG_NOT_NULL(commandLine, err_str_container);
  std::string tempString(commandLine);
  int argc = 0;
  char** argv = VW::to_argv_escaped(tempString, argc);
  const auto scope_exit = VW::scope_exit([argc, argv] { VW::free_args(argc, argv); });
  return VWCreateOptionsFromCommandLine(argc, argv, options_handle, err_str_container);
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWDestroyOptions(VWOptions* options_handle, VWErrorString* err_str_container) noexcept
try
{
  auto* options = from_opaque(options_handle);
  delete options;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsSetString(VWOptions* options_handle, const char* option_name, const char* option_value,
    VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);
  ARG_NOT_NULL(option_value, err_str_container);

  auto* options = from_opaque(options_handle);
  options->replace(option_name, option_value);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsSetInteger(
    VWOptions* options_handle, const char* option_name, int32_t option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);

  auto* options = from_opaque(options_handle);
  options->replace(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsSetFloat(
    VWOptions* options_handle, const char* option_name, float option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);

  auto* options = from_opaque(options_handle);
  options->replace(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsSetBool(
    VWOptions* options_handle, const char* option_name, bool option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);

  auto* options = from_opaque(options_handle);
  // TODO - check if passing true or false works
  options->replace(option_name, option_value ? "true" : "false");
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsListPushString(VWOptions* options_handle, const char* option_name,
    const char* option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);
  ARG_NOT_NULL(option_value, err_str_container);
  auto* options = from_opaque(options_handle);
  options->insert(option_name, option_value);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsListPushInteger(
    VWOptions* options_handle, const char* option_name, int32_t option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);

  auto* options = from_opaque(options_handle);
  options->insert(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWOptionsListPushFloat(
    VWOptions* options_handle, const char* option_name, float option_value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(option_name, err_str_container);

  auto* options = from_opaque(options_handle);
  options->insert(option_name, std::to_string(option_value));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)