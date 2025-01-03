#include "T100ApplicationWindows.h"
#include "T100DX12.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T100ApplicationWindows      app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);


    app.Create();
    T100DX12                    dx12(app.getHWND());

    dx12.start();
    dx12.render();
    app.Show();

    return app.run();
}
