#include "T100Application.h"

#include "T100DX12.h"

HWND        T100Application::m_hwnd             = nullptr;

T100Application::T100Application()
{
    //ctor
}

T100Application::~T100Application()
{
    //dtor
}

HWND T100Application::GetHwnd()
{
    return m_hwnd;
}

int T100Application::Run(T100DX12* pDX12, HINSTANCE hInstance, int nCmdShow)
{
    int             argc;
    LPWSTR*         argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    pDX12->ParseCommandLineArgs(argv, argc);
    LocalFree(argv);

    WNDCLASSEXW             windowClass = { 0 };
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.lpszClassName = L"DXSampleClass";
    RegisterClassExW(&windowClass);

    RECT windowRect = { 0, 0, static_cast<LONG>(pDX12->GetWidth()), static_cast<LONG>(pDX12->GetHeight()) };
    AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

    m_hwnd = CreateWindowW(
        windowClass.lpszClassName,
        pDX12->GetTitle(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        nullptr,
        nullptr,
        hInstance,
        pDX12);

    pDX12->OnInit();

    ShowWindow(m_hwnd, nCmdShow);

    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    pDX12->OnDestroy();

    return static_cast<char>(msg.wParam);
}

LRESULT CALLBACK T100Application::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100DX12* pDX12 = reinterpret_cast<T100DX12*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

    switch (message)
    {
    case WM_CREATE:
        {
            LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));
        }
        return 0;

    case WM_KEYDOWN:
        if (pDX12)
        {
            pDX12->OnKeyDown(static_cast<UINT8>(wParam));
        }
        return 0;

    case WM_KEYUP:
        if (pDX12)
        {
            pDX12->OnKeyUp(static_cast<UINT8>(wParam));
        }
        return 0;

    case WM_PAINT:
        if (pDX12)
        {
            pDX12->OnUpdate();
            pDX12->OnRender();
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
