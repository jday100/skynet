#include "T100MainFrame.h"

#include "T100DX12Renderer.h"

T100DX12Renderer*       m_dx12          = NULL;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

T100MainFrame::T100MainFrame()
{
    //ctor
}

T100MainFrame::~T100MainFrame()
{
    //dtor
}

void T100MainFrame::create()
{
    m_dx12  = new T100DX12Renderer(m_hwnd);

    m_dx12->start();
}

void T100MainFrame::destroy()
{

}

void T100MainFrame::show()
{

}

void T100MainFrame::run(HINSTANCE hInstance, TCHAR name[], int nCmdShow)
{
    HWND            hwnd;
    MSG             message;
    WNDCLASSEX      wincl;

    wincl.hInstance         = hInstance;
    wincl.lpszClassName     = name;
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

    m_hwnd  = hwnd;
    create();

    ShowWindow(hwnd, nCmdShow);

    while(GetMessage(&message, NULL, 0, 0)){
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    destroy();
}


LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message){
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        if(m_dx12){
            m_dx12->Render();
        }
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

