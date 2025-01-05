#include "T100ApplicationWindow.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T100ApplicationWindow       app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    app.Create(_T("CodeBlocksWindowsApp"), _T("Code::Blocks Template Windows App"), DefaultWindowProcedure);
    app.Show();

    return app.Run();
}
