// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include <stdbool.h>

#include "types.h"
#include "exports.h"

#ifdef __cplusplus
extern "C"
{
#endif

  vw_err_str* create_err_str();
  const char* to_c_str(vw_err_str*);
  void destroy_err_str(vw_err_str*);

  VW_DLL_PUBLIC vw_status create_options(vw_options**, vw_err_str* err_string);
  VW_DLL_PUBLIC vw_status create_from_command_line(int argc, char** argv, vw_options**, vw_err_str*);
  VW_DLL_PUBLIC vw_status create_from_command_line_cstr(const char*, vw_options**, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_str(vw_options*, const char* opt_name, const char*, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_int32(vw_options*, const char* opt_name, int32_t, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_set_float(vw_options*, const char* opt_name, float, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_str(vw_options*, const char* opt_name, const char*, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_int32(vw_options*, const char* opt_name, int32_t, vw_err_str*);
  VW_DLL_PUBLIC vw_status options_list_push_float(vw_options*, const char* opt_name, float, vw_err_str*);
  VW_DLL_PUBLIC vw_status delete_options(vw_options*, vw_err_str*);

  VW_DLL_PUBLIC vw_status initialize(vw_options*, bool skipModelLoad, trace_message_func trace_listener,
      void* trace_context, vw_workspace** output, vw_err_str*);
  VW_DLL_PUBLIC vw_status initialize_with_model(vw_options*, void* context, read_func reader, bool skipModelLoad,
      trace_message_func trace_listener, void* trace_context, vw_workspace** output, vw_err_str*);
  VW_DLL_PUBLIC vw_status seed_vw_model(const vw_workspace*, vw_options* opts, trace_message_func trace_listener,
      void* trace_context, vw_workspace**, vw_err_str*);

  vw_status free_string(const char*, vw_err_str*);
  // Returns name of first incompatible feature.
  vw_status are_features_compatible(const vw_workspace*, const vw_workspace*, const char**,
      vw_err_str*);  // Probably better to return an enum with enum->string mappings available?

  VW_DLL_PUBLIC vw_status get_id(vw_workspace* all, const char**, vw_err_str*);
  VW_DLL_PUBLIC vw_status get_command_line(vw_workspace* all, const char**, vw_err_str*);

  // finish is now broken up into finish() and delete_vw().
  VW_DLL_PUBLIC vw_status finish(vw_workspace* all, vw_err_str*);
  VW_DLL_PUBLIC vw_status delete_vw(vw_workspace* all, vw_err_str*);

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
