// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include "vw/experimental/types.h"

#include "owned_string.h"

#include "vw.h"


#define FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)\
CPP_TYPE* from_opaque(C_TYPE* ptr) \
{ \
  return reinterpret_cast<CPP_TYPE*>(ptr); \
}\
const CPP_TYPE* from_opaque(const C_TYPE* ptr) \
{ \
  return reinterpret_cast<const CPP_TYPE*>(ptr); \
}

#define TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)\
C_TYPE* to_opaque(CPP_TYPE* ptr) \
{ \
  return reinterpret_cast<C_TYPE*>(ptr); \
}\
const C_TYPE* to_opaque(const CPP_TYPE* ptr) \
{ \
  return reinterpret_cast<const C_TYPE*>(ptr); \
}

#define TO_FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)\
  FROM_OPAQUE_FUNCS(C_TYPE, CPP_TYPE) \
  TO_OPAQUE_FUNCS(C_TYPE, CPP_TYPE)

// Does not support to_opaque because owned_string can be either VWErrorString* or VWString*
FROM_OPAQUE_FUNCS(VWErrorString, owned_string);
FROM_OPAQUE_FUNCS(VWString, owned_string);
FROM_OPAQUE_FUNCS(VWOptions, VW::config::options_i);

TO_FROM_OPAQUE_FUNCS(VWWorkspace, vw);