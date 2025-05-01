#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "T100HelloFrame.h"
#include "T100Win32Application.h"

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    T100Win32Application        app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
    T100HelloFrame              frame;

    frame.Create(L"T100HelloApplication", 800, 600);

    app.SetFramePtr(&frame);
    app.Create();

    return app.Run();
}
