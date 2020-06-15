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

VW_DLL_PUBLIC VWStatus VWCreateWorkspace(VWOptions* options_handle, bool skip_model_load,
    VWTraceMessageFunc trace_listener, void* trace_context, VWWorkspace** output_handle,
    VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(options_handle, err_str_container);
  ARG_NOT_NULL(output_handle, err_str_container);

  auto* options = from_opaque(options_handle);

  // TODO let workspace understand error code based message tracer
  *output_handle = to_opaque(VW::initialize(*options, nullptr, skip_model_load, nullptr, nullptr));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWCreateWorkspaceWithModel(VWOptions* options_handle, void* context, VWReadFunc* read_func,
    bool skip_model_load, VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
    VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(options_handle, err_str_container);
  ARG_NOT_NULL(read_func, err_str_container);
  ARG_NOT_NULL(output_handle, err_str_container);

  auto* options = from_opaque(options_handle);

  io_buf model_buffer;
  model_buffer.add_file(VW::make_unique<c_reader>(context, read_func));

  // TODO let workspace understand error code based message tracer
  *output_handle = to_opaque(VW::initialize(*options, &model_buffer, skip_model_load, nullptr, nullptr));

  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWCreateSeededWorkspace(const VWWorkspace* existing_workspace_hadnle,
    VWOptions* extra_options_handle, VWTraceMessageFunc* trace_listener, void* trace_context,
    VWWorkspace** output_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(existing_workspace_hadnle, err_str_container);
  ARG_NOT_NULL(output_handle, err_str_container);
  // TODO seed_vw_model can take a const version but it needs to be implemented
  auto* existing_vw = from_opaque(const_cast<VWWorkspace*>(existing_workspace_hadnle));

  std::string extra_command_line = "";
  if (extra_options_handle != nullptr)
  {
    const auto* options = from_opaque(extra_options_handle);
    extra_command_line = get_command_line(options);
  }

  // TODO let workspace understand error code based message tracer
  *output_handle = to_opaque(VW::seed_vw_model(existing_vw, extra_command_line, nullptr, nullptr));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// Returns name of first incompatible feature.
// TODO deprecate this...
// Probably better to return an enum with enum->string mappings available?
VW_DLL_PUBLIC VWStatus VWWorkspaceAreFeaturesCompatibleLegacy(const VWWorkspace* workspace_handle_one,
    const VWWorkspace* workspace_handle_two, const char** incompatible_feature,
    VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle_one, err_str_container);
  ARG_NOT_NULL(workspace_handle_two, err_str_container);

  const auto* w1 = from_opaque(workspace_handle_one);
  const auto* w2 = from_opaque(workspace_handle_two);

  // TODO are_features_compatible should take const parameters
  *incompatible_feature = VW::are_features_compatible(*const_cast<vw*>(w1), *const_cast<vw*>(w2));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelID(
    const VWWorkspace* workspace_handle, const char** model_id, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(model_id, err_str_container);

  const auto* workspace = from_opaque(workspace_handle);
  *model_id = workspace->id.c_str();
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceSetModelID(
    VWWorkspace* workspace_handle, const char* model_id, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(model_id, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  workspace->id = model_id;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetCommandLine(
    const VWWorkspace* workspace_handle, VWString* command_line, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(command_line, err_str_container);

  const auto* workspace = from_opaque(workspace_handle);
  auto* owned_command_line = from_opaque(command_line);
  owned_command_line->string_data = get_command_line(workspace->options);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// finish is now broken up into finish() and destroy_workspace().
VW_DLL_PUBLIC VWStatus VWWorkspaceFinish(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  VW::finish(*workspace, false /*delete_all*/);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWDestroyWorkspace(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  delete workspace;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetPredictionType(
    const VWWorkspace* workspace_handle, VWPredictionType* prediction_type, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* vwObject = from_opaque(workspace_handle);

  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetLabelType(
    const VWWorkspace* workspace_handle, VWLabelType* label_type, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// These are "Legacy" variants because predictions and labels are in the example object
VW_DLL_PUBLIC VWStatus VWWorkspaceLearnLegacy(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceLearnMultilineLegacy(VWWorkspace* workspace_handle, VWExample* example_handle_list,
    size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspacePredictLegacy(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspacePredictMultilineLegacy(VWWorkspace* workspace_handle, VWExample* example_handle_list,
    size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// finish one or more examples? How do we handle multi_ex?
VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExample(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExampleMultiline(VWWorkspace* workspace_handle, VWExample* example_handle_list,
    size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// End pass -> workspace.passes_complete++, in_pass_counter = 0; (something?)
VW_DLL_PUBLIC VWStatus VWWorkspaceEndPass(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus VWWorkspaceGetSearch(
    const VWWorkspace* workspace_handle, VWSearch** search_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)
