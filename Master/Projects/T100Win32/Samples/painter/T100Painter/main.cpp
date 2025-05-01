#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "T100Painter.h"
#include "T100PainterInvoking.h"
#include "T100Win32Application.h"

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    T100Win32Application        app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
    T100Painter                 painter;

    T100PainterInvoking::Create(&painter);

    painter.Create();

    app.SetFramePtr(&painter.GetView().GetFrame());
    app.Create();

    return app.Run();
}
