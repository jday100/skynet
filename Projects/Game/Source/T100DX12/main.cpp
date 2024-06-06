#include <tchar.h>
#include <windows.h>

#include "T100Win.h"


int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    T100Win         win;
    TCHAR name[ ] = _T("CodeBlocksWindowsApp");
    win.Run(hThisInstance, name, nCmdShow);

    return 0;
}
