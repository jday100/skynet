//asm(".long 0x1badb002, 0, (-(0x1badb002 + 0))");

#include "display.h"

#ifdef __cplusplus
extern "C" {
#endif

const char* str = "Hello world!";

int start_entry(void)
{
    hard_display_print(str);
}


#ifdef __cplusplus
}
#endif
