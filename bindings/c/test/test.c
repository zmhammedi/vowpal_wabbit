#include <stdio.h>

#include "vw/experimental/example.h"
#include "vw/experimental/vw.h"

#define PRINT_IF_FAILED(result)                          \
  if (result != VW_SUCCESS)                              \
  {                                                      \
    printf("Failed\n");                                  \
    printf("%s\n", vw_error_string_to_c_string(errorString)); \
    vw_destroy_error_string(errorString); \
    return 1;                                            \
  }

int main()
{
  VWOptions* options;
  VWErrorString* errorString = vw_create_error_string();
  const char* cmdline = "--quiet";

  PRINT_IF_FAILED(vw_create_options_from_command_line_cstring(cmdline, &options, errorString));
  PRINT_IF_FAILED(vw_options_list_push_float(options, "test", 3.5f, errorString));
  PRINT_IF_FAILED(vw_destroy_options(options, errorString));

  VWAllocator* a = vw_get_default_allocator();
  VWExample* ex;
  PRINT_IF_FAILED(vw_create_example(&ex, a, errorString));
  PRINT_IF_FAILED(vw_destroy_example(ex, a, errorString));

  vw_destroy_error_string(errorString);
  return 0;
}