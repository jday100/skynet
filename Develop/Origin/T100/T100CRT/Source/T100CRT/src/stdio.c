#include "stdio.h"

#include <windows.h>

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

