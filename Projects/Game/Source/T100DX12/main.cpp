#include "T100Frame.h"

int WINAPI WinMain (
                    HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow
                    )
{
    T100Frame           frame(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    frame.Create(_T("CodeBlocksWindowsApp"), _T("Code::Blocks Template Windows App"));

    frame.Show();

    return frame.Run();
}

