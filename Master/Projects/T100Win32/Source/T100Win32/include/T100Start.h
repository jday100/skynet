#ifndef T100START_H
#define T100START_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "T100Win32Application.h"

#define START(x) \
int WINAPI WinMain (HINSTANCE hThisInstance, \
                     HINSTANCE hPrevInstance, \
                     LPSTR lpszArgument, \
                     int nCmdShow) \
{ \
    T100Win32Application        app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow); \
\
    app.Create(L"T100Win32Application"); \
\
    return app.Run(); \
}


#endif // T100START_H
