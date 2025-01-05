#include "T100Demo.h"

int WINAPI WinMain (
                    HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow
                    )
{
    T100Demo        demo(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    demo.Create(_T("T100GameDemo"), _T("T100GameDemo"));

    demo.Show();

    return demo.Run();
}

