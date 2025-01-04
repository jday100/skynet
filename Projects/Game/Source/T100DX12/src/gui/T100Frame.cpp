#include "T100Frame.h"
#include "T100Game.h"

HWND T100Frame::m_hwnd      = nullptr;

T100Frame::T100Frame()
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
}

HWND T100Frame::GetHwnd()
{
    return m_hwnd;
}

int T100Frame::Run(T100Game* game, HINSTANCE hInstance, int nCmdShow)
{
    int     argc;

    LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    game->ParseCommandLineArgs(argv, argc);
    LocalFree(argv);

    WNDCLASSEXW      windowClass     = {0};

    windowClass.cbSize          = sizeof(WNDCLASSEX);
    windowClass.style           = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc     = WindowProc;
    windowClass.hInstance       = hInstance;
    windowClass.hCursor         = LoadCursor(NULL, IDC_ARROW);
    windowClass.lpszClassName   = L"DXSampleClass";
    RegisterClassExW(&windowClass);

    RECT    windowRect = {0, 0,
                            static_cast<LONG>(game->GetWidth()),
                            static_cast<LONG>(game->GetHeight())};
    AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

    m_hwnd  = CreateWindowW(
                           windowClass.lpszClassName,
                           game->GetTitle(),
                           WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT,
                           CW_USEDEFAULT,
                           windowRect.right - windowRect.left,
                           windowRect.bottom - windowRect.top,
                           nullptr,
                           nullptr,
                           hInstance,
                           game
                           );

    game->OnInit();

    ShowWindow(m_hwnd, nCmdShow);

    MSG         msg = {};

    while(msg.message != WM_QUIT)
    {
        if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    game->OnDestroy();

    return static_cast<char>(msg.wParam);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100Game*   game    = reinterpret_cast<T100Game*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch(message)
    {
    case WM_CREATE:
        {
            LPCREATESTRUCT  pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);

            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct));
        }
        return 0;
    case WM_KEYDOWN:
        {
            if(game){
                game->OnKeyDown(static_cast<UINT8>(wParam));
            }
        }
        return 0;
    case WM_KEYUP:
        {
            if(game){
                game->OnKeyUp(static_cast<UINT8>(wParam));
            }
        }
        return 0;
    case WM_PAINT:
        {
            if(game){
                game->OnUpdate();
                game->OnRender();
            }
        }
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
