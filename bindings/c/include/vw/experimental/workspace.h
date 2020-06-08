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
  VW_DLL_PUBLIC vw_status create_workspace(vw_options*, bool skipModelLoad, trace_message_func trace_listener,
      void* trace_context, vw_workspace** output, vw_err_str*);
  VW_DLL_PUBLIC vw_status create_workspace_with_model(vw_options*, void* context, read_func reader, bool skipModelLoad,
      trace_message_func trace_listener, void* trace_context, vw_workspace** output, vw_err_str*);
  VW_DLL_PUBLIC vw_status seed_workspace(const vw_workspace*, vw_options* opts, trace_message_func trace_listener,
      void* trace_context, vw_workspace**, vw_err_str*);

  // Returns name of first incompatible feature.
  // TODO deprecate this...
  vw_status are_features_compatible(const vw_workspace*, const vw_workspace*, vw_str*,
      vw_err_str*);  // Probably better to return an enum with enum->string mappings available?

  VW_DLL_PUBLIC vw_status get_model_id(vw_workspace* all, const char**, vw_err_str*);
  VW_DLL_PUBLIC vw_status set_model_id(vw_workspace* all, const char*, vw_err_str*);
  VW_DLL_PUBLIC vw_status get_command_line(vw_workspace* all, const char**, vw_err_str*);

  // finish is now broken up into finish() and destroy_workspace().
  VW_DLL_PUBLIC vw_status finish(vw_workspace* all, vw_err_str*);
  VW_DLL_PUBLIC vw_status destroy_workspace(vw_workspace* all, vw_err_str*);

  VW_DLL_PUBLIC vw_status vw_get_pred_type(vw_workspace* vw, vw_prediction_type*, vw_err_str*);
  VW_DLL_PUBLIC vw_status vw_get_label_type(vw_workspace* vw, vw_label_type*, vw_err_str*);

  VW_DLL_PUBLIC vw_status learn(vw_workspace* vw, vw_example* example, vw_err_str*);
  VW_DLL_PUBLIC vw_status learn_multiline(vw_workspace* vw, vw_example* example, size_t len, vw_err_str*);

  VW_DLL_PUBLIC vw_status predict(vw_workspace* vw, vw_example* example, vw_err_str*);
  VW_DLL_PUBLIC vw_status predict_multiline(vw_workspace* vw, vw_example* example, size_t len, vw_err_str*);

  // finish one or more examples? How do we handle multi_ex?
  VW_DLL_PUBLIC vw_status finish_example(vw_workspace*, vw_example*, vw_err_str*);
  VW_DLL_PUBLIC vw_status finish_example_multiline(vw_workspace*, vw_example*, size_t, vw_err_str*);

  // End pass -> all.passes_complete++, in_pass_counter = 0; (something?)
  VW_DLL_PUBLIC vw_status end_pass(vw_workspace* vw, vw_err_str*);

#ifdef __cplusplus
}
#endif
