#include "T100WindowBase.h"

#include "T100Win32Application.h"
#include "gui/window/T100WindowStyle.h"

T100WindowBase::T100WindowBase() :
    T100EventHandler(),
    m_style()
{
    //ctor
}

T100WindowBase::T100WindowBase(T100WindowBase* parent) :
    T100EventHandler(parent),
    m_style()
{
    //ctor
}

T100WindowBase::~T100WindowBase()
{
    //dtor
}

HWND T100WindowBase::GetHWND()
{
    return m_hwnd;
}

T100VOID T100WindowBase::SetLabel(T100WSTRING label)
{
    m_style.WindowLabel     = label;
}

T100WSTRING T100WindowBase::GetLabel()
{
    return m_style.WindowLabel;
}

T100VOID T100WindowBase::SetWidth(T100INT width)
{
    m_style.Width   = width;
}

T100INT T100WindowBase::GetWidth()
{
    return m_style.Width;
}

T100VOID T100WindowBase::SetHeight(T100INT height)
{
    m_style.Height  = height;
}

T100INT T100WindowBase::GetHeight()
{
    return m_style.Height;
}

T100VOID T100WindowBase::SetSize(T100Size size)
{
    m_style.Width   = size.width;
    m_style.Height  = size.height;

    //SetWindowPos(m_hwnd, NULL, m_style.X, m_style.Y, m_style.Width, m_style.Height, SW_SHOW);
    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);

    T100WindowMessageData   data(0, WM_SIZE, 0, 0);
    SendWindowMessage(data);
}

T100VOID T100WindowBase::SetSize(T100INT width, T100INT height)
{
    SetSize(T100Size(width, height));
}

T100Size T100WindowBase::GetSize()
{
    RECT        rect;
    GetWindowRect(m_hwnd, &rect);

    m_style.Width   = rect.right - rect.left;
    m_style.Height  = rect.bottom - rect.top;

    return T100Size(m_style.Width, m_style.Height);
}

T100VOID T100WindowBase::SetPosition(T100Point value)
{
    m_style.X   = value.x;
    m_style.Y   = value.y;

    MoveWindow(m_hwnd, m_style.X, m_style.Y, m_style.Width, m_style.Height, T100TRUE);
}

T100Point T100WindowBase::GetPosition()
{
    return T100Point(m_style.X, m_style.Y);
}

T100VOID T100WindowBase::Show()
{
    ShowWindow(m_hwnd, SW_SHOW);
}

T100VOID T100WindowBase::Hide()
{
    ShowWindow(m_hwnd, SW_HIDE);
}

T100BOOL T100WindowBase::RegisterWindowClass(T100WindowStyle* style, WNDPROC procedure)
{
    if(!style){
        return T100FALSE;
    }

    WNDCLASSEX  wincl;

    wincl.hInstance         = GetApplicationPtr()->GetThisInstance();
    wincl.lpszClassName     = style->ClassType.c_str();
    wincl.lpfnWndProc       = procedure;
    wincl.style             = style->ClassStyle;
    wincl.cbSize            = sizeof (WNDCLASSEX);

    wincl.hIcon             = NULL;
    wincl.hIconSm           = NULL;
    wincl.hCursor           = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName      = NULL;
    wincl.cbClsExtra        = 0;
    wincl.cbWndExtra        = 0;

    wincl.hbrBackground     = (HBRUSH) COLOR_BACKGROUND;

    if (RegisterClassEx (&wincl)){
        return T100TRUE;
    }
    return T100FALSE;
}

HWND T100WindowBase::CreateWindowInstance(
    HWND parent,
    T100WindowStyle* stylePtr,
    T100VOID* value)
{
    HWND    hwnd;

    if(parent){
        hwnd    = parent;
    }else{
        hwnd    = HWND_DESKTOP;
    }

    T100WindowStyle& style = * stylePtr;

    m_hwnd = CreateWindowEx (
           stylePtr->ExStyle,
           stylePtr->ClassType.c_str(),
           stylePtr->WindowLabel.c_str(),
           stylePtr->WindowStyle,
           stylePtr->X,
           stylePtr->Y,
           stylePtr->Width,
           stylePtr->Height,
           hwnd,
           stylePtr->Menu,
           GetApplicationPtr()->GetThisInstance(),
           value
           );
    return m_hwnd;
}


