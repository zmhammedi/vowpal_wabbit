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

  VW_DLL_PUBLIC VWStatus VWCreateWorkspace(VWOptions*, bool skipModelLoad, VWTraceMessageFunc trace_listener,
      void* trace_context, VWWorkspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWCreateWorkspaceWithModel(VWOptions*, void* context, VWReadFunc reader, bool skipModelLoad,
      VWTraceMessageFunc trace_listener, void* trace_context, VWWorkspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWSeedWorkspace(const VWWorkspace*, VWOptions* opts, VWTraceMessageFunc trace_listener,
      void* trace_context, VWWorkspace**, VWErrorString*);

  // Returns name of first incompatible feature.
  // TODO deprecate this...
  VW_DLL_PUBLIC VWStatus VWWorkspaceAreFeaturesCompatibleLegacy(const VWWorkspace*, const VWWorkspace*, const char**,
      VWErrorString*);  // Probably better to return an enum with enum->string mappings available?

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelID(VWWorkspace* all, const char**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceSetModelID(VWWorkspace* all, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetCommandLine(VWWorkspace* all, VWString*, VWErrorString*);

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinish(VWWorkspace* all, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWDestroyWorkspace(VWWorkspace* all, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetPredictionType(VWWorkspace* vw, VWPredictionType*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetLabelType(VWWorkspace* vw, VWLabelType*, VWErrorString*);

  // TODO add multipredict

  // These are "Legacy" variants because predictions and labels are in the example object
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnLegacy(VWWorkspace* vw, VWExample* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceLearnMultilineLegacy(
      VWWorkspace* vw, VWExample* example, size_t len, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWWorkspacePredictLegacy(VWWorkspace* vw, VWExample* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspacePredictMultilineLegacy(
      VWWorkspace* vw, VWExample* example, size_t len, VWErrorString*);

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExample(VWWorkspace*, VWExample*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceFinishExampleMultiline(VWWorkspace*, VWExample*, size_t, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWWorkspaceEndPass(VWWorkspace* vw, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetSearch(VWWorkspace* vw, VWSearch** search, VWErrorString*);

#ifdef __cplusplus
}
#endif
