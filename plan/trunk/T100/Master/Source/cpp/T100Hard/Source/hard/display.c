#include "display.h"

void hard_display_print(const char* value)
{
    unsigned char* video = (unsigned char*)HARD_DISPLAY_BUFFER_ADDRESS;

    int i;
    for(i = 0; value[i]; i++){
        video[i * 2 + 0] = value[i];
        video[i * 2 + 1] = 0x17;
    }
    for(; i < 80 * 25; i++){
        video[i * 2 + 0] = ' ';
        video[i * 2 + 1] = 0x17;
    }
    while(1) {}
}

