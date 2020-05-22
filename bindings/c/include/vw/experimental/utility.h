// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#pragma once

#include "exports.h"
#include "types.h"

// bool
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Saving
vw_status save_predictor(const vw_workspace* all, void* context, write_func writer);

// Hashing
// The one passed in options
vw_hash_type vw_get_default_hash_type(const vw_workspace*);
uint64_t vw_get_default_hash_seed(const vw_workspace*);
uint64_t vw_get_num_bits(const vw_workspace*);
uint64_t vw_hash_all(const uint8_t* data, size_t length, uint64_t seed, vw_hash_type type);

// SPEEDY overloads for direct hashing against the type
uint64_t vw_hash_all(const uint8_t* data, size_t length, uint64_t seed);
uint64_t vw_hash_string(const char* data, size_t length, uint64_t seed);

// Can also be done as: HASH & ((1 << num_bits) - 1)
uint64_t apply_parse_mask(const vw_workspace* all, uint64_t hash);

// Weights
uint32_t get_parameter_width(const vw_workspace*);
vw_status get_model_parameter(const vw_workspace* all, size_t index, float** weight, size_t* width);
vw_status set_weight(const vw_workspace* all, size_t index, const float* weight, size_t width);

vw_status get_weight_iterator_begin(const vw_workspace* all, vw_weight_iter** iter);
// Will fail if you're already at the end.
vw_status weight_iterator_advance(vw_weight_iter* iter);
bool weight_iterator_can_advance(const vw_weight_iter* iter);
vw_status weight_iterator_deref(const vw_weight_iter* iter, size_t* index, float** weight, size_t* width);

#ifdef __cplusplus
}
#endif