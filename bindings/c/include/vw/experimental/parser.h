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

  vw_status start_parser(vw_workspace*); // Do we want to specify which parser to start here? Currently its done via options
  vw_status end_parser(vw_workspace*);
  
  bool is_ring_example(const vw_workspace*, const example*);  // Returns false if a user-defined example factory was used to create an example
  
  vw_status read_example(vw_workspace*, const char* line, example_factory_t*, void* example_factory_context, example**, size_t*);  // might return a multiline example in the case of the json parser
  vw_status parse_example_label(vw_workspace*, example*, const char* label);
  vw_status setup_example(vw_workspace*, example*);  // Maybe deprecate this. Seems to be doing stuff that should be done in read/import_example
  
  vw_status new_unused_example(vw_workspace*, example_factory_t, void* example_factory_context, example**);  // block if pool is used and there are no free examples, factory behavior if factory is used 
  example* get_parsed_example(vw_workspace*);  // What happens if there are no parsed examples? Block or nullptr.
  
  void finish_example(vw_workspace*, example*, size_t); // finish one or more examples? How do we handle multi_ex? 
  void clear_example(vw_workspace*, example*);

#ifdef __cplusplus
}
#endif
