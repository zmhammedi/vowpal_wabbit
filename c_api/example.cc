// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.
#include "vw/example.h"

#include "example.h"

vw_status example_get_feature_space_indices(const vw_example* ex, unsigned char** indices)
{
  const auto* e = reinterpret_cast<const example*>(ex);
  *indices = &e->indices[0];
  return vw_success;
}

vw_status example_get_feature_space_indices_length(const vw_example* ex, int* length)
{
  const auto* e = reinterpret_cast<const example*>(ex);
  *length = e->indices.size();
  return vw_success;
}

vw_status example_set_feature_space_index(vw_example* ex, int index, int value)
{
  auto* e = reinterpret_cast<example*>(ex);
  if(index >= e->indices.size())
  {
    return vw_fail;
  }

  e->indices[index] = value;
  return vw_success;
}

vw_status example_push_feature_space_index(vw_example*, int value)
{
  return vw_not_implemented;
}

vw_status example_remove_feature_space_index(vw_example*, int index)
{
  return vw_not_implemented;
}

vw_status example_get_feature_space_copy(vw_example* ex, int index, vw_feature_space** fs)
{
  auto* e = reinterpret_cast<example*>(ex);
  auto* new_features = new features();
  new_features->deep_copy_from(e->feature_space[index]);
  *fs = reinterpret_cast<vw_feature_space*>(new_features);
  return 0;
}

vw_status example_get_feature_space_reference(vw_example* ex, int index, vw_feature_space_ref** fs)
{
  auto* e = reinterpret_cast<example*>(ex);
  *fs = reinterpret_cast<vw_feature_space_ref*>(&e->feature_space[index]);
  return 0;
}

vw_status example_assign_feature_space(vw_example* ex, int index, const vw_feature_space* fs)
{
  auto* e = reinterpret_cast<example*>(ex);
  auto* fsss = reinterpret_cast<const features*>(fs);
  e->feature_space[index].deep_copy_from(*fsss);
  return 0;
}

VW_DLL_PUBLIC vw_status feature_space_copy_from_ref(vw_feature_space_ref*, vw_feature_space**)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_copy(vw_feature_space*, vw_feature_space**)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status allocate_feature_space(vw_feature_space**)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status deallocate_feature_space(vw_feature_space*)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_features_length(const vw_feature_space*, int* length)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_get_feature(vw_feature_space*, int index, uint64_t* ft_index, float* ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_set_feature(vw_feature_space*, int index, uint64_t ft_index, float ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_push_feature(vw_feature_space*, uint64_t ft_index, float ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_remove_feature(vw_feature_space*, int index)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_ref_features_length(const vw_feature_space_ref*, int* length)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_ref_get_feature(vw_feature_space_ref*, int index, uint64_t* ft_index, float* ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_ref_set_feature(vw_feature_space_ref*, int index, uint64_t ft_index, float ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_ref_push_feature(vw_feature_space_ref*,  uint64_t ft_index, float ft_value)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status feature_space_ref_remove_feature(vw_feature_space_ref*, int index)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_get_interactions(const vw_example* ex, vw_interactions** out_interactions)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_set_interactions(vw_example*, vw_interactions* interactions)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status interactions_get_interactions_length(const vw_interactions*, int* out_length)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status interactions_get_interaction(const vw_interactions*, char** interaction)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status interactions_set_interaction(vw_interactions*, const char* interaction)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status interactions_push_interaction(vw_interactions*, const char* interaction)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_get_feature_offset(const vw_example*, int* feature_offset)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_set_feature_offset(vw_example*, int feature_offset )
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_get_tag(const vw_example*, const char** tag)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_set_tag(vw_example*, const char* tag)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_get_weight(const vw_example*, float* tag)
{
  return vw_not_implemented;
}

VW_DLL_PUBLIC vw_status example_set_weight(vw_example*, float tag)
{
  return vw_not_implemented;
}
