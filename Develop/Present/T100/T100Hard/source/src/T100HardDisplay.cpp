#include "T100HardDisplay.h"

volatile unsigned int* const DISPLAY_ADDRESS        = (unsigned int*)0xb8000;

void hard_print(wchar_t* text)
{
    while(*text != L'\0'){
        *DISPLAY_ADDRESS = (unsigned int)(*text);
        text++;
    }
}