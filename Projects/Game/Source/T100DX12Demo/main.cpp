#include "T100App.h"

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpArgument,
                   int nCmdShow)
{
    T100App         app(hThisInstance, hPrevInstance, lpArgument, nCmdShow);

    return app.Run();
}
