#include "windows/gui/T100ApplicationWindows.h"
#include "T1003DGame.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T100ApplicationWindows      app(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);
    T1003DGame                  game;

    app.Create();

    game.setHWND(app.getHWND());

    app.Show();

    return app.run();
}
