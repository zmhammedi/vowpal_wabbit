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

  vw_status create_options(vw_options**);
  vw_status create_from_command_line(int argc, char** argv, vw_options**);
  vw_status create_from_command_line(const char*, vw_options**);

  vw_status options_set_str(vw_options*, const char* opt_name, const char*);
  vw_status options_set_int32(vw_options*, const char* opt_name, int32_t);
  vw_status options_set_float(vw_options*, const char* opt_name, float);

  vw_status options_list_push_str(vw_options*, const char* opt_name, const char*);
  vw_status options_list_push_int32(vw_options*, const char* opt_name, int32_t);
  vw_status options_list_push_float(vw_options*, const char* opt_name, float);
  void delete_options(vw_options*);

  typedef void* trace_message_t;

  vw_status initialize(
      vw_options*, bool skipModelLoad, trace_message_t trace_listener, void* trace_context, vw_workspace** output);
  vw_status initialize_with_model(vw_options*, void* context, read_func writer, bool skipModelLoad,
      trace_message_t trace_listener, void* trace_context, vw_workspace** output);
  vw_status seed_vw_model(
      const vw_workspace*, vw_options* opts, trace_message_t trace_listener, void* trace_context, vw_workspace**);

  const char* are_features_compatible(const vw_workspace*,
      const vw_workspace*);  // Probably better to return an enum with enum->string mappings available?

  // finish is now broken up into finish() and delete_vw().
  void finish(vw_workspace* all);
  void delete_vw(vw_workspace* all);

  vw_status vw_get_pred_type(vw_workspace* vw, int);
  vw_status vw_get_label_type(vw_workspace* vw, int);

  vw_status learn(vw_workspace* vw, vw_example* example);
  vw_status learn_multiline(vw_workspace* vw, vw_example* example, int len);

  vw_status predict(vw_workspace* vw, vw_example* example);
  vw_status predict_multiline(vw_workspace* vw, vw_example* example, int len);

#ifdef __cplusplus
}
#endif
