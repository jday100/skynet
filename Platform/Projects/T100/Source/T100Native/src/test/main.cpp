#include "T100ApplicationWindow.h"
#include "T100D3D12.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T100ApplicationWindow       app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    app.Create(_T("CodeBlocksWindowsApp"), _T("Code::Blocks Template Windows App"), DefaultWindowProcedure);

    T100D3D12                   d3d12(app.GetHWND());

    app.Show();

    return app.Run();
}
