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

  VW_DLL_PUBLIC VWStatus VWCreateWorkspace(VWOptions* optionsHandle, bool skipModelLoad, VWTraceMessageFunc* traceListener,
      void* trace_context, VWWorkspace** output, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateWorkspaceWithModel(VWOptions*, void* context, VWReadFunc* reader, bool skipModelLoad,
      VWTraceMessageFunc* traceListener, void* trace_context, VWWorkspace** output, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWCreateSeededWorkspace(const VWWorkspace*, VWOptions* extra_options, VWTraceMessageFunc* traceListener,
      void* trace_context, VWWorkspace**, VWErrorString*) VW_API_NOEXCEPT;

  // Returns name of first incompatible feature.
  // Probably better to return an enum with enum->string mappings available?
  // TODO deprecate this...
  VW_DLL_PUBLIC VWStatus VWWorkspaceAreFeaturesCompatibleLegacy(const VWWorkspace*, const VWWorkspace*, const char**,
      VWErrorString*) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelID(const VWWorkspace* workspace, const char**, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceSetModelID(VWWorkspace* workspace, const char*, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetCommandLine(const VWWorkspace* workspace, VWString*, VWErrorString*) VW_API_NOEXCEPT;

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinish(VWWorkspace* workspace, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWDestroyWorkspace(VWWorkspace* workspace, VWErrorString*) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetPredictionType(const VWWorkspace* vw, VWPredictionType*, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetLabelType(const VWWorkspace* vw, VWLabelType*, VWErrorString*) VW_API_NOEXCEPT;

  // TODO add multipredict

  // These are "Legacy" variants because predictions and labels are in the example object
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnLegacy(VWWorkspace* vw, VWExample* example, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnMultilineLegacy(
      VWWorkspace* vw, VWExample* example, size_t len, VWErrorString*) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspacePredictLegacy(VWWorkspace* vw, VWExample* example, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspacePredictMultilineLegacy(
      VWWorkspace* vw, VWExample* example, size_t len, VWErrorString*) VW_API_NOEXCEPT;

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExample(VWWorkspace*, VWExample*, VWErrorString*) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExampleMultiline(VWWorkspace*, VWExample*, size_t, VWErrorString*) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceEndPass(VWWorkspace* vw, VWErrorString*) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetSearch(const VWWorkspace* vw, VWSearch** search, VWErrorString*) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif
