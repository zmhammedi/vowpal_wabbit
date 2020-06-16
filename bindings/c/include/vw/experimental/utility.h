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

  VWErrorString* VWCreateErrorString() VW_API_NOEXCEPT;
  void VWDestroyErrorString(const VWErrorString* err_str_container) VW_API_NOEXCEPT;
  const char* VWErrorStringToCString(const VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VWString* VWCreateString() VW_API_NOEXCEPT;
  void VWDestroyString(const VWString* str_container) VW_API_NOEXCEPT;
  const char* VWStringToCString(const VWString* str_container) VW_API_NOEXCEPT;

  // Saving
  VW_DLL_PUBLIC VWStatus VWWorkspaceSaveModel(const VWWorkspace* workspace_handle, void* context, VWWriteFunc* writer,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Hashing
  // The one passed in options
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredAudit(
      const VWWorkspace* workspace_handle, bool* audit, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredInputType(
      const VWWorkspace* workspace_handle, VWInputType* input_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHashType(
      const VWWorkspace* workspace_handle, VWHashType* hash_type, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHashSeed(
      const VWWorkspace* workspace_handle, uint64_t* hash_seed, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredNumBits(
      const VWWorkspace* workspace_handle, uint64_t* num_bits, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHasher(
      const VWWorkspace* workspace_handle, VWHasher** hasher, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWHash(const uint8_t* data, size_t length, uint64_t seed, VWHashType type, uint64_t*,
      VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // SPEEDY overloads for direct hashing against the type
  VW_DLL_PUBLIC VWStatus VWHashAll(
      const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWHashString(
      const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Can also be done as: HASH & ((1 << num_bits) - 1)
  VW_DLL_PUBLIC VWStatus VWWorkspaceApplyParseMask(
      const VWWorkspace* workspace_handle, uint64_t hash, uint64_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  // Weights
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetNumWeights(
      const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetParameterWidth(
      const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetWeightsPerProblem(
      const VWWorkspace* workspace_handle, uint32_t*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelParameter(const VWWorkspace* workspace_handle, size_t index, float** weight,
      size_t* width, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWorkspaceSetWeight(const VWWorkspace* workspace_handle, size_t index, const float* weight,
      size_t width, VWErrorString* err_str_container) VW_API_NOEXCEPT;

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetWeightIteratorBegin(
      const VWWorkspace* workspace_handle, VWWeightIterator** iter, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  // Will fail if you're already at the end.
  VW_DLL_PUBLIC VWStatus VWWeightIteratorAdvance(
      VWWeightIterator* iter, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWeightIteratorCanAdvance(
      const VWWeightIterator* iter, bool*, VWErrorString* err_str_container) VW_API_NOEXCEPT;
  VW_DLL_PUBLIC VWStatus VWWeightIteratorDereference(const VWWeightIterator* iter, size_t* index, float** weight,
      size_t* width, VWErrorString* err_str_container) VW_API_NOEXCEPT;

#ifdef __cplusplus
}
#endif