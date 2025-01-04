#include "T100Frame.h"
#include "T100DX12Demo.h"

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    T100DX12Demo        demo(1280, 720, L"D3D12 Bundles Sample");

    return T100Frame::Run(&demo, hThisInstance, nCmdShow);
}

