#ifndef T100WIN32START_H
#define T100WIN32START_H

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "gui/T100Win32Application.h"

using namespace T100WINDOWS;

#define     T100Win32Start(Application) \
int WINAPI WinMain (HINSTANCE hThisInstance, \
                     HINSTANCE hPrevInstance, \
                     LPSTR lpCmdLine, \
                     int nCmdShow) \
{ \
    Application         app; \
    return T100Runner(app, hThisInstance, hPrevInstance, lpCmdLine, nCmdShow); \
}

#endif // T100WIN32START_H
