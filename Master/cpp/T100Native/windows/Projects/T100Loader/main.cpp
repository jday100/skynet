#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

#include "T100Loader.h"

using namespace T100WINDOWS;

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszCmdLine,
                     int nCmdShow)
{
    T100WSTRING         filename    = L"./build/T100Loader.exe";
    T100Loader          loader;

    loader.Load(filename);

    return 0;
}


