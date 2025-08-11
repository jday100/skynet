#include "stdio.h"

#include <windows.h>

int strlen(const char* value)
{
    int result  = 0;

    do{
        if(value[result++] == '\0'){
            break;
        }
    }while(true);
    return result;
}

int printf(const char* value, ...)
{
    HANDLE          handle;
    DWORD           written;
    INT             length;
    const char*     buffer;

    buffer  = value;
    length  = strlen(buffer);

    handle = GetStdHandle(STD_OUTPUT_HANDLE);

    WriteFile(handle, buffer, length, &written, NULL);

    return 0;
}

