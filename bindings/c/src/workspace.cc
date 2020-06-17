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
#include "vw/experimental/types.h"
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

VW_DLL_PUBLIC VWStatus vw_create_workspace(VWOptions* options_handle, bool skip_model_load,
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

VW_DLL_PUBLIC VWStatus vw_create_workspace_with_model(VWOptions* options_handle, void* context, VWReadFunc* read_func,
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

VW_DLL_PUBLIC VWStatus vw_create_seeded_workspace(const VWWorkspace* existing_workspace_handle,
    VWOptions* extra_options_handle, VWTraceMessageFunc* trace_listener, void* trace_context,
    VWWorkspace** output_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(existing_workspace_handle, err_str_container);
  ARG_NOT_NULL(output_handle, err_str_container);
  // TODO seed_vw_model can take a const version but it needs to be implemented
  auto* existing_vw = from_opaque(const_cast<VWWorkspace*>(existing_workspace_handle));

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

VW_DLL_PUBLIC VWStatus vw_workspace_get_model_id(
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

VW_DLL_PUBLIC VWStatus vw_workspace_set_model_id(
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

VW_DLL_PUBLIC VWStatus vw_workspace_get_command_line(
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
VW_DLL_PUBLIC VWStatus vw_workspace_finish(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  VW::finish(*workspace, false /*delete_all*/);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_destroy_workspace(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  delete workspace;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_get_prediction_type(
    const VWWorkspace* workspace_handle, VWPredictionType* prediction_type, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(prediction_type, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  *prediction_type = internal_to_c_enum(workspace->l->pred_type);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_get_label_type(
    const VWWorkspace* workspace_handle, VWLabelType* label_type, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(label_type, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  *label_type = internal_to_c_enum(workspace->label_type);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// These are "Legacy" variants because predictions and labels are in the example object
VW_DLL_PUBLIC VWStatus vw_workspace_learn_legacy(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example = from_opaque(example_handle);
  workspace->learn(*example);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_learn_multiline_legacy(VWWorkspace* workspace_handle,
    VWExample** example_handle_list, size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle_list, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example_list = reinterpret_cast<example**>(example_handle_list);
  std::vector<example*> example_vec(example_list, example_list + example_handle_list_length);
  workspace->learn(example_vec);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_predict_legacy(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example = from_opaque(example_handle);
  workspace->predict(*example);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_predict_multiline_legacy(VWWorkspace* workspace_handle,
    VWExample* example_handle_list, size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle_list, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example_list = reinterpret_cast<example**>(example_handle_list);
  std::vector<example*> example_vec(example_list, example_list + example_handle_list_length);
  workspace->predict(example_vec);

  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// finish one or more examples? How do we handle multi_ex?
VW_DLL_PUBLIC VWStatus vw_workspace_finish_example(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example = from_opaque(example_handle);
  workspace->finish_example(*example);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_finish_example_multiline(VWWorkspace* workspace_handle,
    VWExample* example_handle_list, size_t example_handle_list_length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(example_handle_list, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  auto* example_list = reinterpret_cast<example**>(example_handle_list);
  std::vector<example*> example_vec(example_list, example_list + example_handle_list_length);
  workspace->finish_example(example_vec);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// End pass -> workspace.passes_complete++, in_pass_counter = 0; (something?)
VW_DLL_PUBLIC VWStatus vw_workspace_end_pass(VWWorkspace* workspace_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  workspace->passes_complete++;
  workspace->p->in_pass_counter = 0;
  workspace->l->end_pass();
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_get_search(
    const VWWorkspace* workspace_handle, VWSearch** search_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle, err_str_container);
  ARG_NOT_NULL(search_handle, err_str_container);
  auto* workspace = from_opaque(workspace_handle);
  *search_handle = reinterpret_cast<VWSearch*>(workspace->searchstr);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)
