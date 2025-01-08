#include <windows.h>

#include "T100FireGame.h"

_Use_decl_annotations_
int WINAPI WinMain(
                  HINSTANCE hThisInstance,
                  HINSTANCE hPrevInstance,
                  LPSTR lpArgument,
                  int nCmdShow
                  )
{
    T100FireGame            game(hThisInstance, hPrevInstance, lpArgument, nCmdShow);

    game.create(1280, 720, L"D3D12 Sample");
    game.show();

    return game.run();
}
