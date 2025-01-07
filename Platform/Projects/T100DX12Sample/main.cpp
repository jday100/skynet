#include "stdafx.h"
#include "T100D3D12HelloTriangle.h"

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    T100D3D12HelloTriangle      sample(1280, 720, L"D3D12 Hello Triangle");
    return T100Win32Application::Run(&sample, hInstance, nCmdShow);
}
