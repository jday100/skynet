#include "T100Win.h"

#include <tchar.h>
#include <windows.h>

#include "T100DX12Renderer.h"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
//TCHAR szClassName[] = _T("CodeBlocksWindowsApp");

T100Win::T100Win()
{
    //ctor
}

T100Win::~T100Win()
{
    //dtor
}

T100VOID T100Win::Run(HINSTANCE hInstance, TCHAR name[], int nCmdShow)
{
    HWND            hwnd;
    MSG             message;
    WNDCLASSEX      wincl;

    wincl.hInstance         = hInstance;
    wincl.lpszClassName     = name;         //szClassName;
    wincl.lpfnWndProc       = WindowProcedure;
    wincl.style             = CS_DBLCLKS;
    wincl.cbSize            = sizeof(WNDCLASSEX);

    wincl.hIcon             = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm           = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor           = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName      = NULL;
    wincl.cbClsExtra        = 0;
    wincl.cbWndExtra        = 0;

    wincl.hbrBackground     = (HBRUSH)COLOR_BACKGROUND;

    if(!RegisterClassEx(&wincl)){
        return;
    }

    hwnd    = CreateWindowEx(
                            0,
                            name,
                            _T("Code::Blocks Template Windows App"),
                            WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            544,
                            375,
                            HWND_DESKTOP,
                            NULL,
                            hInstance,
                            NULL
                            );

    Create();

    ShowWindow(hwnd, nCmdShow);

    while(GetMessage(&message, NULL, 0, 0)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    Destroy();
}


LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message){
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

T100VOID T100Win::Create()
{
    T100DX12Renderer*       dx12;

    dx12    = T100NEW T100DX12Renderer();

    dx12->Start();
}

T100VOID T100Win::Destroy()
{

}
