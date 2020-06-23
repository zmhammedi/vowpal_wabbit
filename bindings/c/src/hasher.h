// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include "parse_primitives.h"

struct vw_hasher
{
  // typedef uint64_t (*hash_func_t)(const char* s, size_t length, uint64_t seed);
  hash_func_t _hash_func;
  uint64_t _hash_seed;

  //  all.parse_mask = ((uint64_t)1 << all.num_bits) - 1;
  uint64_t _parse_mask;
};
