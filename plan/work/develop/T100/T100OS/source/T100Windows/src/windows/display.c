#include "windows/display.h"

#include <windows.h>
#include <winbase.h>

void printf(char* value)
{
    HMODULE module = GetModuleHandleA("msvcrt.dll");

    void(*method)(char*) = (void(*)(char*))GetProcAddress(module, "printf");

    if(method){
        method(value);
    }
}
