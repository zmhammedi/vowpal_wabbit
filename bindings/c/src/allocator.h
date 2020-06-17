#pragma once

#include <cstddef>
#include <cstdlib>

using alloc_func = void*(size_t num, size_t size);
using dealloc_func = void(void* ptr, size_t num);

struct vw_allocator
{
  alloc_func* _alloc;
  dealloc_func* _dealloc;
};

inline void* default_allocator(size_t num, size_t size) noexcept { return std::calloc(num, size); }
inline void default_deallocator(void* ptr, size_t /*num*/) noexcept { return std::free(ptr); }
