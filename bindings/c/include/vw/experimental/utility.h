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
  void VWDestroyErrorString(VWErrorString*) VW_API_NOEXCEPT;
  const char* VWErrorStringToCString(VWErrorString*) VW_API_NOEXCEPT;

  VWString* VWCreateString() VW_API_NOEXCEPT;
  void VWDestroyString(VWString*) VW_API_NOEXCEPT;
  const char* VWStringToCString(VWString*) VW_API_NOEXCEPT;

  // Saving
  VW_DLL_PUBLIC VWStatus VWWorkspaceSaveModel(const VWWorkspace* all, void* context, VWWriteFunc writer, VWErrorString*);

  // Hashing
  // The one passed in options
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredAudit(const VWWorkspace*, bool*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHashType(const VWWorkspace*, VWHashType*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHashSeed(const VWWorkspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredNumBits(const VWWorkspace*, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetConfiguredHasher(const VWWorkspace*, VWHasher** hasher);

  VW_DLL_PUBLIC VWStatus VWHash(
      const uint8_t* data, size_t length, uint64_t seed, VWHashType type, uint64_t*, VWErrorString*);

  // SPEEDY overloads for direct hashing against the type
  VW_DLL_PUBLIC VWStatus VWHashAll(const uint8_t* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWHashString(const char* data, size_t length, uint64_t seed, uint64_t*, VWErrorString*);

  // Can also be done as: HASH & ((1 << num_bits) - 1)
  VW_DLL_PUBLIC VWStatus VWWorkspaceApplyParseMask(const VWWorkspace* all, uint64_t hash, uint64_t*, VWErrorString*);

  // Weights
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetNumWeights(const VWWorkspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetParameterWidth(const VWWorkspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetWeightsPerProblem(const VWWorkspace*, uint32_t*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceGetModelParameter(
      const VWWorkspace* all, size_t index, float** weight, size_t* width, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWorkspaceSetWeight(
      const VWWorkspace* all, size_t index, const float* weight, size_t width, VWErrorString*);

  VW_DLL_PUBLIC VWStatus VWWorkspaceGetWeightIteratorBegin(const VWWorkspace* all, VWWeightIterator** iter, VWErrorString*);
  // Will fail if you're already at the end.
  VW_DLL_PUBLIC VWStatus VWWeightIteratorAdvance(VWWeightIterator* iter, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWeightIteratorCanAdvance(const VWWeightIterator* iter, bool*, VWErrorString*);
  VW_DLL_PUBLIC VWStatus VWWeightIteratorDereference(
      const VWWeightIterator* iter, size_t* index, float** weight, size_t* width, VWErrorString*);

#ifdef __cplusplus
}
#endif