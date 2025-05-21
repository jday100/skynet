#ifndef T100START_H
#define T100START_H

#include "gui/T100Win32Application.h"

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

#define     T100StartApp(App) \
int WINAPI WinMain (HINSTANCE hThisInstance, \
                     HINSTANCE hPrevInstance, \
                     LPSTR lpCmdLine, \
                     int nCmdShow) \
{ \
    App         app; \
    return T100Runner(app, hThisInstance, hPrevInstance, lpCmdLine, nCmdShow); \
}


#define     T100StartFrame(Frame) \
int WINAPI WinMain (HINSTANCE hThisInstance, \
                     HINSTANCE hPrevInstance, \
                     LPSTR lpCmdLine, \
                     int nCmdShow) \
{ \
    T100Win32Application        app; \
    Frame                       frame; \
    app.SetFrame(&frame); \
    frame.Create(&app, L"", 800, 600); \
    frame.Show(); \
    return T100Runner(app, hThisInstance, hPrevInstance, lpCmdLine, nCmdShow); \
}

#define     T100StartFrame(Frame) \
int WINAPI WinMain (HINSTANCE hThisInstance, \
                     HINSTANCE hPrevInstance, \
                     LPSTR lpCmdLine, \
                     int nCmdShow) \
{ \
    T100Win32Application        app; \
    Frame       frame(&app); \
    app.SetFrame(&frame); \
    frame.Create(L"T100Frame"); \
    frame.Show(); \
    return T100Runner(app, hThisInstance, hPrevInstance, lpCmdLine, nCmdShow); \
}

#endif // T100START_H
