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

  VW_DLL_PUBLIC VWErrorString* vw_create_error_string() VW_API_NOEXCEPT;
  VW_DLL_PUBLIC void vw_destroy_error_string(VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC const char* vw_error_string_to_c_string(const VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWString* vw_create_string() VW_API_NOEXCEPT;
  VW_DLL_PUBLIC void vw_destroy_string(VWString* str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC const char* vw_string_to_c_string(const VWString* str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWAllocator* vw_get_default_allocator() VW_API_NOEXCEPT;

  // Saving
  VW_DLL_PUBLIC VWStatus vw_workspace_save_model(VWWorkspace* workspace_handle, void* context,
      VWWriteFunc* writer, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // Will fail if workspace not setup to do this
  VW_DLL_PUBLIC VWStatus vw_workspace_save_readable_model(VWWorkspace* workspace_handle, void* context,
      VWWriteFunc* writer, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // Will fail if workspace not setup to do this
  VW_DLL_PUBLIC VWStatus vw_workspace_save_invert_hash_model(VWWorkspace* workspace_handle, void* context,
      VWWriteFunc* writer, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Hashing
  // The one passed in options
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_audit(
      const VWWorkspace* workspace_handle, bool* audit, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_input_type(
      const VWWorkspace* workspace_handle, VWInputType* input_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hash_type(
      const VWWorkspace* workspace_handle, VWHashType* hash_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hash_seed(
      const VWWorkspace* workspace_handle, uint64_t* hash_seed, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_num_bits(
      const VWWorkspace* workspace_handle, uint64_t* num_bits, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hasher(
      const VWWorkspace* workspace_handle, VWHasher** hasher, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_hash(const uint8_t* data, size_t length, uint64_t seed, VWHashType type, uint64_t*,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // SPEEDY overloads for direct hashing against the type
  VW_DLL_PUBLIC VWStatus vw_hash_all(
      const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_hash_string(
      const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Can also be done as: HASH & ((1 << num_bits) - 1)
  VW_DLL_PUBLIC VWStatus vw_workspace_apply_parse_mask(
      const VWWorkspace* workspace_handle, uint64_t hash, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Weights
  VW_DLL_PUBLIC VWStatus vw_workspace_get_num_weights(
      const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_parameter_width(
      const VWWorkspace* workspace_handle, size_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_weights_per_problem(
      const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_get_weight(const VWWorkspace* workspace_handle, size_t index, float** weight,
      size_t* width, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_workspace_set_weight(const VWWorkspace* workspace_handle, size_t index, const float* weight,
      size_t width, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // This checks whether these two workspaces produce equivalent example objects
  // in the sense that passing an example parsed by one makes sense to one
  // parsed by the other. This does not take into account labels or the
  // reduction stack itself. It checks things like affix features and hasher.
  VW_DLL_PUBLIC VWStatus vw_workspace_is_example_parsing_equivalent(const VWWorkspace* workspace_handle_one,
      const VWWorkspace* workspace_handle_two, const char** incompatible_feature,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus vw_workspace_get_weight_iterator_begin(
      const VWWorkspace* workspace_handle, VWWeightIterator** iter, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // Will fail if you're already at the end.
  VW_DLL_PUBLIC VWStatus vw_weight_iterator_advance(
      VWWeightIterator* iter, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_weight_iterator_can_advance(
      const VWWeightIterator* iter, bool*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus vw_weight_iterator_dereference(const VWWeightIterator* iter, size_t* index, float** weight,
      size_t* width, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif