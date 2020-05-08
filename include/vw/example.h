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

VW_DLL_PUBLIC vw_status example_get_feature_space_indices(const vw_example*, unsigned char** indices);
VW_DLL_PUBLIC vw_status example_get_feature_space_indices_length(const vw_example*, int* length);
VW_DLL_PUBLIC vw_status example_set_feature_space_index(vw_example*, int index, int value);
VW_DLL_PUBLIC vw_status example_push_feature_space_index(vw_example*, int value);
VW_DLL_PUBLIC vw_status example_remove_feature_space_index(vw_example*, int index);

VW_DLL_PUBLIC vw_status example_get_feature_space_copy(vw_example*, int index, vw_feature_space**);
VW_DLL_PUBLIC vw_status example_get_feature_space_reference(vw_example*, int index, vw_feature_space_ref**);
// This will copy into the given feature space BUT NOT RELEASE THE SUPPLIED FEATURE SPACE
VW_DLL_PUBLIC vw_status example_assign_feature_space(vw_example*, int index, const vw_feature_space*);

VW_DLL_PUBLIC vw_status feature_space_copy_from_ref(vw_feature_space_ref*, vw_feature_space**);
VW_DLL_PUBLIC vw_status feature_space_copy(vw_feature_space*, vw_feature_space**);

VW_DLL_PUBLIC vw_status allocate_feature_space(vw_feature_space**);
VW_DLL_PUBLIC vw_status deallocate_feature_space(vw_feature_space*);

VW_DLL_PUBLIC vw_status feature_space_features_length(const vw_feature_space*, int* length);
VW_DLL_PUBLIC vw_status feature_space_get_feature(vw_feature_space*, int index, uint64_t* ft_index, float* ft_value);
VW_DLL_PUBLIC vw_status feature_space_set_feature(vw_feature_space*, int index, uint64_t ft_index, float ft_value);
VW_DLL_PUBLIC vw_status feature_space_push_feature(vw_feature_space*, uint64_t ft_index, float ft_value);
VW_DLL_PUBLIC vw_status feature_space_remove_feature(vw_feature_space*, int index);

VW_DLL_PUBLIC vw_status feature_space_ref_features_length(const vw_feature_space_ref*, int* length);
VW_DLL_PUBLIC vw_status feature_space_ref_get_feature(vw_feature_space_ref*, int index, uint64_t* ft_index, float* ft_value);
VW_DLL_PUBLIC vw_status feature_space_ref_set_feature(vw_feature_space_ref*, int index, uint64_t ft_index, float ft_value);
VW_DLL_PUBLIC vw_status feature_space_ref_push_feature(vw_feature_space_ref*,  uint64_t ft_index, float ft_value);
VW_DLL_PUBLIC vw_status feature_space_ref_remove_feature(vw_feature_space_ref*, int index);

// This must be a copy as by default it references the global interactions definition
VW_DLL_PUBLIC vw_status example_get_interactions_copy(const vw_example*, vw_interactions** out_interactions);
// Need to check if the current value is the global copy - and if it isn't delete it before setting it.
VW_DLL_PUBLIC vw_status example_set_interactions(vw_example*, vw_interactions* interactions);

VW_DLL_PUBLIC vw_status interactions_get_interactions_length(const vw_interactions*, int* out_length);
VW_DLL_PUBLIC vw_status interactions_get_interaction(const vw_interactions*, char** interaction);
VW_DLL_PUBLIC vw_status interactions_set_interaction(vw_interactions*, const char* interaction);
VW_DLL_PUBLIC vw_status interactions_push_interaction(vw_interactions*, const char* interaction);

VW_DLL_PUBLIC vw_status example_get_feature_offset(const vw_example*, int* feature_offset);
VW_DLL_PUBLIC vw_status example_set_feature_offset(vw_example*, int feature_offset );

VW_DLL_PUBLIC vw_status example_get_tag(const vw_example*, const char** tag);
VW_DLL_PUBLIC vw_status example_set_tag(vw_example*, const char* tag);

VW_DLL_PUBLIC vw_status example_get_weight(const vw_example*, float* weight);
VW_DLL_PUBLIC vw_status example_set_weight(vw_example*, float weight);

#ifdef __cplusplus
}
#endif
