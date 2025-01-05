#include "T100Game.h"

int WINAPI WinMain (
                    HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow
                    )
{
    T100Game        game(hThisInstance, hPrevInstance, lpszArgument, nCmdShow);

    game.Create(_T("CodeBlocksWindowsApp"), _T("Code::Blocks Template Windows App"));

    game.Show();

    return game.Run();
}

