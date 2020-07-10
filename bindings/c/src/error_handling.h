// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#pragma once

#include <exception>

#include "owned_string.h"
#include "vw_exception.h"

#define RETURN_IF_FAIL(result)        \
  do                                  \
  {                                   \
    auto result__LINE__ = result;     \
    if (result__LINE__ != VW_SUCCESS) \
    {                                 \
      return result__LINE__;          \
    }                                 \
  } while (0)

#define SET_IF_EXISTS(errorStringContainer, errorStringContent)                        \
  do                                                                                   \
  {                                                                                    \
    if (errorStringContainer != nullptr)                                               \
    {                                                                                  \
      auto* errString__LINE__ = reinterpret_cast<owned_string*>(errorStringContainer); \
      errString__LINE__->string_data = errorStringContent;                             \
    }                                                                                  \
  } while (0)

#define CATCH_RETURN(errorStringContainer)                   \
  catch (const VW::vw_exception& vwException)                \
  {                                                          \
    SET_IF_EXISTS(errorStringContainer, vwException.what()); \
    return VW_FAIL;                                          \
  }                                                          \
  catch (const std::exception& exception)                    \
  {                                                          \
    SET_IF_EXISTS(errorStringContainer, exception.what());   \
    return VW_FAIL;                                          \
  }                                                          \
  catch (...)                                                \
  {                                                          \
    SET_IF_EXISTS(errorStringContainer, "unknown failure");  \
    return VW_FAIL;                                          \
  }

#define ARG_NOT_NULL(arg, errorStringContainer)              \
  do                                                         \
  {                                                          \
    if (arg == nullptr)                                      \
    {                                                        \
      SET_IF_EXISTS(errorStringContainer, #arg " was null"); \
      return VW_INVALID_ARGUMENT;                            \
    }                                                        \
  } while (0)
