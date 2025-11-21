asm(".long 0x1badb002, 0, (-(0x1badb002 + 0))");

#include "display.h"

unsigned char* video = (unsigned char*)HARD_DISPLAY_BUFFER_ADDRESS;
const char* str = "Hello world!";

int start_entry(void)
{
    int i;
    for(i = 0; str[i]; i++){
        video[i * 2 + 0] = str[i];
        video[i * 2 + 1] = 0x17;
    }
    for(; i < 80 * 25; i++){
        video[i * 2 + 0] = ' ';
        video[i * 2 + 1] = 0x17;
    }
    while(1) {}
    return 0;
}
