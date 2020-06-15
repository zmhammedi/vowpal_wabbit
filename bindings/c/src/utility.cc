// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/experimental/utility.h"

#include "owned_string.h"

VWErrorString* VWCreateErrorString() noexcept { return reinterpret_cast<VWErrorString*>(new owned_string()); }
void VWDestroyErrorString(VWErrorString* errorString) noexcept { delete reinterpret_cast<owned_string*>(errorString); }
const char* VWErrorStringToCString(VWErrorString* errorString) noexcept
{
  const auto* ownedString = reinterpret_cast<owned_string*>(errorString);
  return ownedString->string_data.c_str();
}

VWString* VWCreateString() noexcept { return reinterpret_cast<VWString*>(new owned_string()); }
void VWDestroyString(VWString* vwString) noexcept { delete reinterpret_cast<owned_string*>(vwString); }
const char* VWStringToCString(VWString* vwString) noexcept
{
  const auto* ownedString = reinterpret_cast<owned_string*>(vwString);
  return ownedString->string_data.c_str();
}
