#include <stdio.h>

#include "vw/experimental/options.h"
#include "vw/experimental/utility.h"
#include "vw/experimental/vw.h"

#define PRINT_IF_FAILED(result)                          \
  if (result != VW_SUCCESS)                              \
  {                                                      \
    printf("Failed\n");                                  \
    printf("%s\n", VWErrorStringToCString(errorString)); \
    VWDestroyErrorString(errorString); \
    return 1;                                            \
  }

int main()
{
  VWOptions* options;
  VWErrorString* errorString = VWCreateErrorString();
  const char* cmdline = "this is my command line";

  PRINT_IF_FAILED(VWCreateOptionsFromCommandLineCString(cmdline, &options, errorString));
  PRINT_IF_FAILED(VWOptionsListPushFloat(options, "test", 3.5f, errorString));
  // PRINT_IF_FAILED(VWDestroyOptions(options, errorString));
  VWDestroyErrorString(errorString);
  return 0;
}