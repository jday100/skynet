#include "T100Window.h"

#include "gui/common/T100WindowCommon.h"
#include "gui/layout/T100Layout.h"
#include "gui/event/T100ApplicationEventHandler.h"

T100Window::T100Window() :
    T100WindowBase()
{
    //ctor
}

T100Window::T100Window(T100ApplicationEventHandler* app, T100Window* parent) :
    T100WindowBase()
{
    //ctor
    Init(app, parent);
}

T100Window::~T100Window()
{
    //dtor
}

T100VOID T100Window::Create(T100ApplicationEventHandler* app, T100Window* parent)
{
    Init(app, parent);
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

T100Window* T100Window::ConvertToWindow(T100ObjectTreeNode* node)
{
    return dynamic_cast<T100Window*>(node);
}

T100VOID T100Window::Init(T100ApplicationEventHandler* app, T100Window* parent)
{
    T100EventHandler::Create(m_label, parent);

    HINSTANCE       instance;

    instance    = app->GetThisInstance();

    if(app->IsRegistered(T100WINDOW_TYPE_T100WINDOW)){
        CreateWindowHandler(instance);
    }else{
        if(app->RegisterWindowClass(T100WINDOW_TYPE_T100WINDOW)){
            if(RegisterWindowClass(instance, &m_style)){
                CreateWindowHandler(instance);
            }
        }
    }
}

T100VOID T100Window::CreateWindowHandler(HINSTANCE instance)
{
    m_hwnd  = CreateWindowInstance(instance, &m_style);
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

HWND T100Window::CreateWindowInstance(HINSTANCE instance, T100WindowStyle* stylePtr)
{
    HWND    hwnd;

    hwnd    = HWND_DESKTOP;

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
           T100NULL
           );
    return m_hwnd;
}
