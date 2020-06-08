// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

#include "options.h"

#ifdef __cplusplus
extern "C"
{
#endif

  // TODO use destroy naming

  // TODO create_workspace
  VW_DLL_PUBLIC VWStatus create_workspace(vw_options*, bool skipModelLoad, trace_message_func trace_listener,
      void* trace_context, VWWorkspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus create_workspace_with_model(vw_options*, void* context, read_func reader, bool skipModelLoad,
      trace_message_func trace_listener, void* trace_context, VWWorkspace** output, VWErrorString*);
  VW_DLL_PUBLIC VWStatus seed_workspace(const VWWorkspace*, vw_options* opts, trace_message_func trace_listener,
      void* trace_context, VWWorkspace**, VWErrorString*);

  // Returns name of first incompatible feature.
  // TODO deprecate this...
  VWStatus are_features_compatible(const VWWorkspace*, const VWWorkspace*, vw_str*,
      VWErrorString*);  // Probably better to return an enum with enum->string mappings available?

  VW_DLL_PUBLIC VWStatus get_model_id(VWWorkspace* all, const char**, VWErrorString*);
  VW_DLL_PUBLIC VWStatus set_model_id(VWWorkspace* all, const char*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_command_line(VWWorkspace* all, const char**, VWErrorString*);

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC VWStatus finish(VWWorkspace* all, VWErrorString*);
  VW_DLL_PUBLIC VWStatus destroy_workspace(VWWorkspace* all, VWErrorString*);

  VW_DLL_PUBLIC VWStatus vw_get_pred_type(VWWorkspace* vw, vw_prediction_type*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_label_type(VWWorkspace* vw, vw_label_type*, VWErrorString*);

  VW_DLL_PUBLIC VWStatus learn(VWWorkspace* vw, vw_example* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus learn_multiline(VWWorkspace* vw, vw_example* example, size_t len, VWErrorString*);

  VW_DLL_PUBLIC VWStatus predict(VWWorkspace* vw, vw_example* example, VWErrorString*);
  VW_DLL_PUBLIC VWStatus predict_multiline(VWWorkspace* vw, vw_example* example, size_t len, VWErrorString*);

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC VWStatus finish_example(VWWorkspace*, vw_example*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus finish_example_multiline(VWWorkspace*, vw_example*, size_t, VWErrorString*);

  // End pass -> all.passes_complete++, in_pass_counter = 0; (something?)
  VW_DLL_PUBLIC VWStatus end_pass(VWWorkspace* vw, VWErrorString*);

#ifdef __cplusplus
}
#endif
