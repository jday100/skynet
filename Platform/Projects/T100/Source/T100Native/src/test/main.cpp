#include "T100ApplicationWindows.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T100ApplicationWindows      app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    app.Create();
    app.Show();

    return app.run();
}
