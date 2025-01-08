#include "T100Application.h"
#include "T100Demo.h"

int WINAPI WinMain(
                   HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpArgument,
                   int nCmdShow
                   )
{
    T100Demo        demo(1280, 720, L"D3D12 Demo");
    return T100Application::Run(&demo, hThisInstance, nCmdShow);
}
