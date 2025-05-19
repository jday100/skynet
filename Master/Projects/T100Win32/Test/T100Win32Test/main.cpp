#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

#include "T100Win32Test.h"

T100INT WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpCmdLine,
                     T100INT nCmdShow)
{
    T100Win32Test       win32(hThisInstance, hPrevInstance, lpCmdLine, nCmdShow);

    if(win32.TestAll() == T100RESULT_SUCCESS){
        return 0;
    }

    return -1;
}

