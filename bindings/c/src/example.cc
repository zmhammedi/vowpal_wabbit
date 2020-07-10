// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#include "vw/experimental/example.h"
#include "vw/experimental/label.h"

#include "example.h"
#include "allocator.h"
#include "error_handling.h"
#include "interop_helper.h"

VW_DLL_PUBLIC VWStatus vw_create_example(
    VWExample** example_handle, VWAllocator* allocator_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(allocator_handle, err_str_container);

  auto* allocator = from_opaque(allocator_handle);
  void* example_mem = allocator->_alloc(1, sizeof(example));
  if (example_mem == nullptr)
  {
    SET_IF_EXISTS(err_str_container, "failed to allocate");
    return VW_FAIL;
  }

  *example_handle = to_opaque(new (example_mem) example());
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_destroy_example(
    VWExample* example_handle, VWAllocator* allocator_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(allocator_handle, err_str_container);

  auto* allocator = from_opaque(allocator_handle);
  auto* example = from_opaque(example_handle);
  example->~example();
  allocator->_dealloc(example, 1);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
VW_DLL_PUBLIC VWStatus vw_example_setup(
    VWWorkspace* workspace_handle, VWExample* example_handle, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_feature_space_indices(const VWExample* example_handle,
    const unsigned char** indices, size_t* length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(indices, err_str_container);
  ARG_NOT_NULL(length, err_str_container);

  const auto* example = from_opaque(example_handle);
  *indices = &example->indices[0];
  *length = example->indices.size();
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_example_push_feature_space_index(
    VWExample* example_handle, unsigned char value, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  example->indices.push_back(value);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

// invalidates pointers
VW_DLL_PUBLIC VWStatus vw_example_remove_feature_space_index(
    VWExample* example_handle, size_t index, VWErrorString* err_str_container) noexcept
try
{
  // Can't remove at index for v_array...
  SET_IF_EXISTS(err_str_container, "vw_example_remove_feature_space_index is not implemented");
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_feature_space(const VWExample* example_handle, unsigned char index,
    const VWFeatureSpace** feature_space_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(feature_space_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  *feature_space_handle = to_opaque(&example->feature_space[index]);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_feature_space_as_mut(VWExample* example_handle, unsigned char index,
    VWFeatureSpace** feature_space_handle, bool audit, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(feature_space_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  auto* fs = &example->feature_space[index];
  fs->audit = audit;
  *feature_space_handle = to_opaque(fs);

  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_feature_space(VWExample* example_handle, unsigned char index,
    const VWFeatureSpace* feature_space_handle, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(feature_space_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  auto* fs = reinterpret_cast<const features*>(feature_space_handle);
  example->feature_space[index].deep_copy_from(*fs);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_feature_offset(
    const VWExample* example_handle, int* feature_offset, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(feature_offset, err_str_container);

  const auto* example = from_opaque(example_handle);
  *feature_offset = example->ft_offset;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_feature_offset(
    VWExample* example_handle, int feature_offset, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  example->ft_offset = feature_offset;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_tag(
    const VWExample* example_handle, const char** tag, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(tag, err_str_container);

  const auto* example = from_opaque(example_handle);
  *tag = &example->tag[0];
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_tag(
    VWExample* example_handle, const char* tag, int length, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(tag, err_str_container);

  auto* example = from_opaque(example_handle);
  example->tag.clear();
  push_many(example->tag, tag, length);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_weight(
    const VWExample* example_handle, float* weight, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(weight, err_str_container);

  const auto* example = from_opaque(example_handle);
  *weight = example->weight;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_weight(
    VWExample* example_handle, float weight, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);

  auto* example = from_opaque(example_handle);
  example->weight = weight;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_label(
    VWExample* example_handle, VWLabel** label, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(label, err_str_container);

  auto* example = from_opaque(example_handle);
  *label = reinterpret_cast<VWLabel*>(&example->l);
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_label(
    VWExample* example_handle, const VWLabel* label, VWLabelType label_type, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(label, err_str_container);
  auto* example = from_opaque(example_handle);
  auto* dest_label = reinterpret_cast<VWLabel*>(&example->l);
  RETURN_IF_FAIL(vw_copy_label(dest_label, label, label_type, err_str_container));
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_prediction(
    const VWExample* example_handle, VWPrediction** prediction, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_prediction(VWExample* example_handle, VWPrediction* prediction,
    VWPredictionType prediction_type, VWErrorString* err_str_container) noexcept
try
{
  return VW_NOT_IMPLEMENTED;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_partial_prediction(
    const VWExample* example_handle, float* partial_prediction, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(partial_prediction, err_str_container);
  auto* example = from_opaque(example_handle);
  *partial_prediction = example->partial_prediction;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_updated_prediction(
    const VWExample* example_handle, float* updated_prediction, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(updated_prediction, err_str_container);
  auto* example = from_opaque(example_handle);
  *updated_prediction = example->updated_prediction;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_loss(
    const VWExample* example_handle, float* loss, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(loss, err_str_container);
  auto* example = from_opaque(example_handle);
  *loss = example->loss;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_total_sum_feat_sq(
    const VWExample* example_handle, float* total_sum_feat_sq, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(total_sum_feat_sq, err_str_container);
  auto* example = from_opaque(example_handle);
  *total_sum_feat_sq = example->total_sum_feat_sq;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_get_test_only(
    const VWExample* example_handle, bool* test_only, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  ARG_NOT_NULL(test_only, err_str_container);
  auto* example = from_opaque(example_handle);
  *test_only = example->test_only;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)

VW_DLL_PUBLIC VWStatus vw_example_set_test_only(
    VWExample* example_handle, bool test_only, VWErrorString* err_str_container) noexcept
try
{
  ARG_NOT_NULL(example_handle, err_str_container);
  auto* example = from_opaque(example_handle);
  example->test_only = test_only;
  return VW_SUCCESS;
}
CATCH_RETURN(err_str_container)
