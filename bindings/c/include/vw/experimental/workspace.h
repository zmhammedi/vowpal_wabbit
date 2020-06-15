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

  VW_DLL_PUBLIC VWStatus VWCreateWorkspace(VWOptions* options_handle, bool skip_model_load,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateWorkspaceWithModel(VWOptions* options_handle, void* context, VWReadFunc* reader, bool skip_model_load,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateSeededWorkspace(const VWWorkspace* existing_workspace_handle, VWOptions* extra_options_handle,
      VWTraceMessageFunc* trace_listener, void* trace_context, VWWorkspace** output_handle,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Returns name of first incompatible feature.
  // Probably better to return an enum with enum->string mappings available?
  // TODO deprecate this...
  VW_DLL_PUBLIC VWStatus VWWorkspaceAreFeaturesCompatibleLegacy(const VWWorkspace* workspace_handle_one,
      const VWWorkspace* workspace_handle_two, const char** incompatible_feature,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelID(
      const VWWorkspace* workspace_handle, const char** model_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceSetModelID(
      VWWorkspace* workspace_handle, const char* model_id, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetCommandLine(
      const VWWorkspace* workspace_handle, VWString* command_line, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinish(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWDestroyWorkspace(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetPredictionType(
      const VWWorkspace* workspace_handle, VWPredictionType* prediction_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetLabelType(
      const VWWorkspace* workspace_handle, VWLabelType* label_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // TODO add multipredict

  // These are "Legacy" variants because predictions and labels are in the example object
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnLegacy(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnMultilineLegacy(VWWorkspace* workspace_handle, VWExample* example_handle_list,
      size_t example_handle_list_length, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspacePredictLegacy(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspacePredictMultilineLegacy(VWWorkspace* workspace_handle,
      VWExample* example_handle_list, size_t example_handle_list_length,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExample(
      VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExampleMultiline(VWWorkspace* workspace_handle,
      VWExample* example_handle_list, size_t example_handle_list_length,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceEndPass(
      VWWorkspace* workspace_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetSearch(
      const VWWorkspace* workspace_handle, VWSearch** search_handle, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
