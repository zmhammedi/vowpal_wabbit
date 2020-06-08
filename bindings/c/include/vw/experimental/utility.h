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

  VWErrorString* create_err_str();
  const char* err_to_c_str(VWErrorString*);
  void destroy_err_str(VWErrorString*);

  VWErrorString* create_vw_str();
  const char* strto_c_str(vw_str*);
  void destroy_vw_str(vw_str*);

  // Saving
  VW_DLL_PUBLIC VWStatus save_predictor(const vw_workspace* all, void* context, write_func writer, VWErrorString*);

  // Hashing
  // The one passed in options
  VW_DLL_PUBLIC VWStatus vw_get_default_hash_type(const vw_workspace*, vw_hash_type*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_default_hash_seed(const vw_workspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_num_bits(const vw_workspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_hash(
      const uint8_t* data, size_t length, uint64_t seed, vw_hash_type type, uint64_t*, VWErrorString*);

  // SPEEDY overloads for direct hashing against the type
  VW_DLL_PUBLIC VWStatus vw_hash_all(const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_hash_string(const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);

  // Can also be done as: HASH & ((1 << num_bits) - 1)
  VW_DLL_PUBLIC VWStatus apply_parse_mask(const vw_workspace* all, uint64_t hash, uint64_t*, VWErrorString*);

  // Weights
  VW_DLL_PUBLIC VWStatus get_num_weights(const vw_workspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_parameter_width(const vw_workspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_model_parameter(
      const vw_workspace* all, size_t index, float** weight, size_t* width, VWErrorString*);
  VW_DLL_PUBLIC VWStatus set_weight(
      const vw_workspace* all, size_t index, const float* weight, size_t width, VWErrorString*);

  VW_DLL_PUBLIC VWStatus get_weight_iterator_begin(const vw_workspace* all, vw_weight_iter** iter, VWErrorString*);
  // Will fail if you're already at the end.
  VW_DLL_PUBLIC VWStatus weight_iterator_advance(vw_weight_iter* iter, VWErrorString*);
  VW_DLL_PUBLIC VWStatus weight_iterator_can_advance(const vw_weight_iter* iter, bool*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus weight_iterator_deref(
      const vw_weight_iter* iter, size_t* index, float** weight, size_t* width, VWErrorString*);

#ifdef __cplusplus
}
#endif