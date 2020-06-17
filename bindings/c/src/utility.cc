// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/utility.h"
#include <memory>

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

using alloc_func = void*(size_t num, size_t size);
using dealloc_func = void(void* ptr, size_t num);
struct allocator
{
  alloc_func* _alloc;
  dealloc_func* _dealloc;
};

void* default_allocator(size_t num, size_t size) noexcept { return std::calloc(num, size); }

void default_deallocator(void* ptr, size_t /*num*/) noexcept { return std::free(ptr); }

allocator global_alloc{default_allocator, default_deallocator};

VW_DLL_PUBLIC VWAllocator* vw_get_default_allocator() noexcept { return reinterpret_cast<VWAllocator*>(&global_alloc); }