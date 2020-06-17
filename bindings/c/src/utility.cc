// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/utility.h"
#include <memory>

#include "allocator.h"
#include "error_handling.h"
#include "interop_helper.h"
#include "owned_string.h"

VW_DLL_PUBLIC VWErrorString* vw_create_error_string() noexcept
{
  return reinterpret_cast<VWErrorString*>(new owned_string());
}
VW_DLL_PUBLIC void vw_destroy_error_string(VWErrorString* errorString) noexcept
{
  delete reinterpret_cast<owned_string*>(errorString);
}

VW_DLL_PUBLIC const char* vw_error_string_to_c_string(const VWErrorString* errorString) noexcept
{
  const auto* ownedString = reinterpret_cast<const owned_string*>(errorString);
  return ownedString->string_data.c_str();
}

VW_DLL_PUBLIC VWString* vw_create_string() noexcept { return reinterpret_cast<VWString*>(new owned_string()); }
VW_DLL_PUBLIC void vw_destroy_string(VWString* vwString) noexcept { delete reinterpret_cast<owned_string*>(vwString); }
VW_DLL_PUBLIC const char* vw_string_to_c_string(const VWString* vwString) noexcept
{
  const auto* ownedString = reinterpret_cast<const owned_string*>(vwString);
  return ownedString->string_data.c_str();
}

vw_allocator global_alloc{default_allocator, default_deallocator};
VW_DLL_PUBLIC VWAllocator* vw_get_default_allocator() noexcept { return reinterpret_cast<VWAllocator*>(&global_alloc); }

// Saving
VW_DLL_PUBLIC VWStatus vw_workspace_save_model(
    const VWWorkspace* workspace_handle, void* context, VWWriteFunc* writer, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// Will fail if workspace not setup to do this
VW_DLL_PUBLIC VWStatus vw_workspace_save_readable_model(
    const VWWorkspace* workspace_handle, void* context, VWWriteFunc* writer, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// Will fail if workspace not setup to do this
VW_DLL_PUBLIC VWStatus vw_workspace_save_invert_hash_model(
    const VWWorkspace* workspace_handle, void* context, VWWriteFunc* writer, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// The one passed in options
VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_audit(
    const VWWorkspace* workspace_handle, bool* audit, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_input_type(
    const VWWorkspace* workspace_handle, VWInputType* input_type, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hash_type(
    const VWWorkspace* workspace_handle, VWHashType* hash_type, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hash_seed(
    const VWWorkspace* workspace_handle, uint64_t* hash_seed, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_num_bits(
    const VWWorkspace* workspace_handle, uint64_t* num_bits, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_configured_hasher(
    const VWWorkspace* workspace_handle, VWHasher** hasher, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_hash(const uint8_t* data, size_t length, uint64_t seed, VWHashType type, uint64_t*,
    VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// SPEEDY overloads for direct hashing against the type
VW_DLL_PUBLIC VWStatus vw_hash_all(
    const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_hash_string(
    const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// Can also be done as: HASH & ((1 << num_bits) - 1)
VW_DLL_PUBLIC VWStatus vw_workspace_apply_parse_mask(
    const VWWorkspace* workspace_handle, uint64_t hash, uint64_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// Weights
VW_DLL_PUBLIC VWStatus vw_workspace_get_num_weights(
    const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_parameter_width(
    const VWWorkspace* workspace_handle, size_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_weights_per_problem(
    const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_get_weight(const VWWorkspace* workspace_handle, size_t index, float** weight,
    size_t* width, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_set_weight(const VWWorkspace* workspace_handle, size_t index, const float* weight,
    size_t width, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_workspace_is_example_parsing_equivalent(const VWWorkspace* workspace_handle_one,
    const VWWorkspace* workspace_handle_two, const char** incompatible_feature,
    VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(workspace_handle_one, err_str_container);
  ARG_NOT_NULL(workspace_handle_two, err_str_container);

  const auto* w1 = from_opaque(workspace_handle_one);
  const auto* w2 = from_opaque(workspace_handle_two);

  // TODO are_features_compatible should take const parameters
  *incompatible_feature = VW::are_features_compatible(*const_cast<vw*>(w1), *const_cast<vw*>(w2));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_workspace_get_weight_iterator_begin(
    const VWWorkspace* workspace_handle, VWWeightIterator** iter, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

// Will fail if you're already at the end.
VW_DLL_PUBLIC VWStatus vw_weight_iterator_advance(VWWeightIterator* iter, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_weight_iterator_can_advance(
    const VWWeightIterator* iter, bool*, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}

VW_DLL_PUBLIC VWStatus vw_weight_iterator_dereference(const VWWeightIterator* iter, size_t* index, float** weight,
    size_t* width, VWErrorString* err_str_container) noexcept
{
  return VW_NOT_IMPLEMENTED;
}
