#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include "T100MainFrame.h"

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    T100MainFrame       frame;
    TCHAR name[ ]       = _T("CodeBlocksWindowsApp");

    frame.run(hThisInstance, name, nCmdShow);

    return 0;
}



