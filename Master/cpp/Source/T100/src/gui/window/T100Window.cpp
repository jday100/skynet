#include "gui/window/T100Window.h"

#include "gui/common/T100WindowCommon.h"
#include "gui/layout/T100Layout.h"
#include "gui/event/T100ApplicationEventHandler.h"

T100Window::T100Window() :
    T100WindowBase()
{
    //ctor
}

T100Window::T100Window(T100ApplicationEventHandler* app, T100Window* parent, T100WindowStyle* style) :
    T100WindowBase()
{
    //ctor

    Init(app, parent, style);
}

T100Window::~T100Window()
{
    //dtor
}

T100VOID T100Window::Create(T100ApplicationEventHandler* app, T100Window* parent, T100WindowStyle* style)
{
    Init(app, parent, style);
}

T100VOID T100Window::SetLayout(T100Layout* layout)
{
    m_layoutPtr     = layout;

    m_layoutPtr->SetParent(this);
    m_layoutPtr->SetChildren(m_children.getVector());
}

T100Layout* T100Window::GetLayoutPtr()
{
    return m_layoutPtr;
}

T100VOID T100Window::SetStyle(T100WindowStyle style)
{
    m_style = style;
}

T100WindowStyle& T100Window::GetStyle()
{
    return m_style;
}

T100Window* T100Window::ConvertToWindow(T100ObjectTreeNode* node)
{
    return dynamic_cast<T100Window*>(node);
}

T100VOID T100Window::OnWindowResize(T100WindowEvent& event)
{
    if(m_layoutPtr){
        m_layoutPtr->Update();
    }
}

T100VOID T100Window::Init(T100ApplicationEventHandler* app, T100Window* parent, T100WindowStyle* style)
{
    if(app && parent){
        return;
    }

    if(style){
        m_style     = *style;
        m_label     = m_style.WindowLabel;
    }

    HWND        hwnd;

    if(app){
        hwnd    = HWND_DESKTOP;
        T100EventHandler::Create(m_label, app);
    }else if(parent){
        hwnd    = parent->GetHWND();
        T100EventHandler::Create(m_label, parent);
    }

    HINSTANCE       instance;

    instance    = GetApplicationPtr()->GetThisInstance();

    if(GetApplicationPtr()->IsRegistered(m_style.ClassType)){
        CreateWindowHandler(instance, hwnd, GetApplicationPtr());
    }else{
        if(GetApplicationPtr()->RegisterWindowClass(m_style.ClassType)){
            if(RegisterWindowClass(instance, &m_style)){
                CreateWindowHandler(instance, hwnd, GetApplicationPtr());
            }
        }
    }

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnWindowResize);
}

T100VOID T100Window::CreateWindowHandler(HINSTANCE instance, HWND hwnd, T100VOID* data)
{
    m_hwnd  = CreateWindowInstance(instance, hwnd, &m_style, data);
    if(m_hwnd){
        GetApplicationPtr()->GetWindowMessageDispatcher().RegisterWindowHandler(m_hwnd, this);
    }
}

T100BOOL T100Window::RegisterWindowClass(HINSTANCE instance, T100WindowStyle* style)
{
    if(!style){
        return T100FALSE;
    }

    WNDCLASSEX  wincl;

    wincl.hInstance         = instance;
    wincl.lpszClassName     = style->ClassType.c_str();
    wincl.lpfnWndProc       = style->Procedure;
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

HWND T100Window::CreateWindowInstance(HINSTANCE instance, HWND hwnd, T100WindowStyle* stylePtr, T100VOID* data)
{
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
           instance,
           data
           );
    return m_hwnd;
}
