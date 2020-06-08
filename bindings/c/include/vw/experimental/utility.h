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

  VWErrorString* create_VWString();
  const char* strto_c_str(VWString*);
  void destroy_VWString(VWString*);

  // Saving
  VW_DLL_PUBLIC VWStatus save_predictor(const VWWorkspace* all, void* context, VWWriteFunc writer, VWErrorString*);

  // Hashing
  // The one passed in options
  VW_DLL_PUBLIC VWStatus vw_get_default_hash_type(const VWWorkspace*, VWHashType*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_default_hash_seed(const VWWorkspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_get_num_bits(const VWWorkspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_hash(
      const uint8_t* data, size_t length, uint64_t seed, VWHashType type, uint64_t*, VWErrorString*);

  // SPEEDY overloads for direct hashing against the type
  VW_DLL_PUBLIC VWStatus vw_hash_all(const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus vw_hash_string(const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);

  // Can also be done as: HASH & ((1 << num_bits) - 1)
  VW_DLL_PUBLIC VWStatus apply_parse_mask(const VWWorkspace* all, uint64_t hash, uint64_t*, VWErrorString*);

  // Weights
  VW_DLL_PUBLIC VWStatus get_num_weights(const VWWorkspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_parameter_width(const VWWorkspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus get_model_parameter(
      const VWWorkspace* all, size_t index, float** weight, size_t* width, VWErrorString*);
  VW_DLL_PUBLIC VWStatus set_weight(
      const VWWorkspace* all, size_t index, const float* weight, size_t width, VWErrorString*);

  VW_DLL_PUBLIC VWStatus get_weight_iterator_begin(const VWWorkspace* all, VWWeightIterator** iter, VWErrorString*);
  // Will fail if you're already at the end.
  VW_DLL_PUBLIC VWStatus weight_iterator_advance(VWWeightIterator* iter, VWErrorString*);
  VW_DLL_PUBLIC VWStatus weight_iterator_can_advance(const VWWeightIterator* iter, bool*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus weight_iterator_deref(
      const VWWeightIterator* iter, size_t* index, float** weight, size_t* width, VWErrorString*);

#ifdef __cplusplus
}
#endif