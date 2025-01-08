#include "T1003DGame.h"

int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpszArgument,
                  int nCmdShow
                  )
{
    T1003DGame          game(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    game.create(1280, 720, L"D3D12 Sample");
    game.show();

    return game.run();
}
