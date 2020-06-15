// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/workspace.h"

#include "interop_helper.h"
#include "error_handling.h"
#include "c_io_adapter.h"

#include "io/io_adapter.h"
#include "options.h"
#include "vw.h"
#include "options_serializer_boost_po.h"
#include "vw/experimental/utility.h"

std::string get_command_line(const VW::config::options_i* options)
{
  // These APIs really should be const to avoid this...
  auto* local = const_cast<VW::config::options_i*>(options);
  VW::config::options_serializer_boost_po serializer;
  for (auto const& option : local->get_all_options())
  {
    if (local->was_supplied(option->m_name))
    {
      serializer.add(*option);
    }
  }
  return serializer.str();
}

VW_DLL_PUBLIC VWStatus VWCreateWorkspace(VWOptions* options, bool skipModelLoad, VWTraceMessageFunc trace_listener,
    void* trace_context, VWWorkspace** output, VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(options, errorStringContainer);
  ARG_NOT_NULL(output, errorStringContainer);

  auto* options_i = from_opaque(options);

  // TODO let workspace understand error code based message tracer
  *output = to_opaque(VW::initialize(*options_i, nullptr, skipModelLoad, nullptr, nullptr));
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWCreateWorkspaceWithModel(VWOptions* options, void* context, VWReadFunc* readFunc,
    bool skipModelLoad, VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output,
    VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(options, errorStringContainer);
  ARG_NOT_NULL(readFunc, errorStringContainer);
  ARG_NOT_NULL(output, errorStringContainer);

  auto* options_i = from_opaque(options);

  io_buf model_buffer;
  model_buffer.add_file(VW::make_unique<c_reader>(context, readFunc));

  // TODO let workspace understand error code based message tracer
  *output = to_opaque(VW::initialize(*options_i, &model_buffer, skipModelLoad, nullptr, nullptr));

  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWCreateSeededWorkspace(const VWWorkspace* existing_workspace, VWOptions* opts,
    VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output,
    VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(existing_workspace, errorStringContainer);
  ARG_NOT_NULL(output, errorStringContainer);
  // TODO seed_vw_model can take a const version but it needs to be implemented
  auto* existing_vw = from_opaque(const_cast<VWWorkspace*>(existing_workspace));

  std::string extraCommandLine = "";
  if(opts != nullptr)
  {
    const auto* options = from_opaque(opts);
    extraCommandLine = get_command_line(options);
  }

  // TODO let workspace understand error code based message tracer
  *output = to_opaque(VW::seed_vw_model(existing_vw, extraCommandLine, nullptr, nullptr));
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

// Returns name of first incompatible feature.
// TODO deprecate this...
// Probably better to return an enum with enum->string mappings available?
VW_DLL_PUBLIC VWStatus VWWorkspaceAreFeaturesCompatibleLegacy(const VWWorkspace* workspaceOne,
    const VWWorkspace* workspaceTwo, const char** incompatibility, VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(workspaceOne, errorStringContainer);
  ARG_NOT_NULL(workspaceTwo, errorStringContainer);

  const auto* w1 = from_opaque(workspaceOne);
  const auto* w2 = from_opaque(workspaceTwo);

  // TODO are_features_compatible should take const parameters
  *incompatibility = VW::are_features_compatible(*const_cast<vw*>(w1), *const_cast<vw*>(w2));
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelID(
    const VWWorkspace* workspace, const char** modelID, VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(workspace, errorStringContainer);
  ARG_NOT_NULL(modelID, errorStringContainer);

  const auto* castedWorkspace = from_opaque(workspace);
  *modelID = castedWorkspace->id.c_str();
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceSetModelID(
    VWWorkspace* workspace, const char* modelID, VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(workspace, errorStringContainer);
  ARG_NOT_NULL(modelID, errorStringContainer);
  auto* castedWorkspace = from_opaque(workspace);
  castedWorkspace->id = modelID;
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetCommandLine(
    const VWWorkspace* workspace, VWString* commandLine, VWErrorString* errorStringContainer) noexcept
try
{
  ARG_NOT_NULL(workspace, errorStringContainer);
  ARG_NOT_NULL(commandLine, errorStringContainer);

  const auto* vwObject = from_opaque(workspace);
  auto* ownedCommandLine = from_opaque(commandLine);
  ownedCommandLine->string_data = get_command_line(vwObject->options);
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

// finish is now broken up into finish() and destroy_workspace().
VW_DLL_PUBLIC VWStatus VWWorkspaceFinish(VWWorkspace* workspace, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWDestroyWorkspace(VWWorkspace* workspace, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetPredictionType(
    const VWWorkspace* vw, VWPredictionType* predictiontype, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetLabelType(
    const VWWorkspace* vw, VWLabelType* labelType, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

// These are "Legacy" variants because predictions and labels are in the example object
VW_DLL_PUBLIC VWStatus VWWorkspaceLearnLegacy(
    VWWorkspace* vw, VWExample* example, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceLearnMultilineLegacy(
    VWWorkspace* vw, VWExample* example, size_t len, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspacePredictLegacy(
    VWWorkspace* vw, VWExample* example, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspacePredictMultilineLegacy(
    VWWorkspace* vw, VWExample* example, size_t len, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

// finish one or more examples? How do we handle multi_ex?
VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExample(
    VWWorkspace* workspace, VWExample* example, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExampleMultiline(
    VWWorkspace* workspace, VWExample* examplePtr, size_t length, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

// End pass -> workspace.passes_complete++, in_pass_counter = 0; (something?)
VW_DLL_PUBLIC VWStatus VWWorkspaceEndPass(VWWorkspace* vw, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetSearch(
    const VWWorkspace* vw, VWSearch** search, VWErrorString* errorStringContainer) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(errorStringContainer)
