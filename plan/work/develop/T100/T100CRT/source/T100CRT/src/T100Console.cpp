#include "T100Console.h"

void crt_print(const char* value)
{
    HANDLE          handle;
    DWORD           written;
    INT             length;
    const char*     buffer;

    buffer  = value;
    length  = crt_str_len(buffer);

    handle = GetStdHandle(STD_OUTPUT_HANDLE);

    WriteFile(handle, buffer, length, &written, NULL);
}
