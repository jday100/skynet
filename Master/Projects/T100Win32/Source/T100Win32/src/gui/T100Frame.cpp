#include "T100Frame.h"

#include "T100Panel.h"
#include "T100Button.h"
#include "T100FillLayout.h"
#include "T100Win32Application.h"

T100Frame::T100Frame() :
    T100FrameBase()
{
    //ctor
}

T100Frame::~T100Frame()
{
    //dtor
}

T100VOID T100Frame::Create(T100WSTRING title, T100UINT width, T100UINT height)
{
    HWND        hwnd;
    m_width     = width;
    m_height    = height;

    hwnd    = HWND_DESKTOP;

    if(RegisterWindowClass(L"T100Frame")){

        WNDCLASSEX      wincl;

        wincl.hInstance         = T100Win32Application::m_thisInstance;
        wincl.lpszClassName     = L"T100Frame";
        wincl.lpfnWndProc       = T100DefaultFrameProcedure;
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
    }

    m_hwnd = CreateWindowEx(
                    0,
                    L"T100Frame",
                    title.c_str(),
                    WS_OVERLAPPEDWINDOW,
                    CW_USEDEFAULT,
                    CW_USEDEFAULT,
                    width,
                    height,
                    HWND_DESKTOP,
                    NULL,
                    T100Win32Application::m_thisInstance,
                    this
                    );

    Register(m_hwnd, this);
    //init();
}

T100VOID T100Frame::Destroy()
{
    //uninit();
}

T100VOID T100Frame::init()
{
    T100MenuBar*        menuBarPtr      = T100NEW T100MenuBar();

    T100Menu*           fileMenuPtr     = T100NEW T100Menu(menuBarPtr, L"File");

    T100MenuItem*       quitMenuPtr      = T100NEW T100MenuItem(fileMenuPtr, T100MENU_ID_QUIT, L"Quit");

    SetMenuBarPtr(menuBarPtr);

    Connect(T100EVENT_COMMAND, T100MENU_ID_QUIT, (T100EVENT_CALL)&T100Frame::OnMenuQuit);

    T100Panel*          panel       = T100NEW T100Panel();

    panel->Create(this, L"", 400, 300);

    T100Button*         button      = T100NEW T100Button();

    button->SetLabel(L"OK");
    button->Create(panel);

    button->Connect(T100EVENT_COMMAND, (T100EVENT_CALL)&T100Frame::OnButtonClick, this);

    panel->Show();

    T100FillLayout* layout = T100NEW T100FillLayout();

    SetLayoutPtr(layout);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_CALL)&OnResize);
}

T100VOID T100Frame::uninit()
{

}

T100VOID T100Frame::SetMenuBarPtr(T100MenuBar* menuBarPtr)
{
    m_menuBarPtr    = menuBarPtr;
    SetMenu(m_hwnd, m_menuBarPtr->m_menuBar);
}

T100MenuBar* T100Frame::GetMenuBarPtr()
{
    return m_menuBarPtr;
}

T100VOID T100Frame::Show()
{
    ShowWindow(m_hwnd, SW_SHOW);
}

T100VOID T100Frame::Hide()
{

}

T100INT T100Frame::Run()
{
    MSG             messages;

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        ::DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK T100DefaultFrameProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    T100MESSAGE_DATA        data        = {hwnd, message, wParam, lParam};
    T100EventHandler*       handlerPtr  = reinterpret_cast<T100EventHandler*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (message)
    {
        case WM_COMMAND:
        case WM_PAINT:
        case WM_SIZE:
        case WM_CLOSE:
            {
                if(handlerPtr){
                    handlerPtr->DispatchMessage(data);
                }else{
                    return DefWindowProc (hwnd, message, wParam, lParam);
                }
            }
            break;
        case WM_CREATE:
            {
                LPCREATESTRUCT pCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
                SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pCreateStruct->lpCreateParams));

                T100EventHandler*       handlerPtr  = reinterpret_cast<T100EventHandler*>(pCreateStruct->lpCreateParams);
                if(handlerPtr){
                    T100WindowEvent     event(data);
                    handlerPtr->ProcessEvent(event);
                }
            }
            break;
        case WM_DESTROY:
            {
                if(handlerPtr){
                    T100WindowEvent     event(data);
                    handlerPtr->ProcessEvent(event);
                }
                PostQuitMessage (0);
            }
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

T100VOID T100Frame::OnMenuQuit(T100CommandEvent& event)
{
    PostQuitMessage(0);
}

T100VOID T100Frame::OnButtonClick(T100CommandEvent& event)
{
    PostQuitMessage(0);
}
