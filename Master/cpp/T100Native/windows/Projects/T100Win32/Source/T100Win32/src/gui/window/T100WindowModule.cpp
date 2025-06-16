#include "T100WindowModule.h"

#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100WindowModule::T100WindowModule() :
    T100Class()
{
    //ctor
}

T100WindowModule::~T100WindowModule()
{
    //dtor
}

T100BOOL T100WindowModule::RegisterWindowClass(HINSTANCE instance, const T100WindowStyle& style)
{
    WNDCLASSEX          wincl;

    wincl.hInstance     = instance;
    wincl.lpszClassName = style.ClassType.c_str();
    wincl.lpfnWndProc   = style.Procedure;
    wincl.style         = style.ClassStyle;
    wincl.cbSize        = sizeof(WNDCLASSEX);

    wincl.hIcon         = style.Icon;
    wincl.hIconSm       = style.IconSmall;
    wincl.hCursor       = style.Cursor;
    wincl.lpszMenuName  = T100NULL;
    wincl.cbClsExtra    = 0;
    wincl.cbWndExtra    = 0;
    wincl.hbrBackground = style.Background;

    if(RegisterClassEx(&wincl)){
        return T100TRUE;
    }
    return T100FALSE;
}

HWND T100WindowModule::CreateWindowInstance(HINSTANCE instance, HWND parent, const T100WindowStyle& style, T100VOID* data)
{
    HWND        result;

    result  = CreateWindowEx (
                    style.ExStyle,
                    style.ClassType.c_str(),
                    style.WindowLabel.c_str(),
                    style.WindowStyle,
                    style.X,
                    style.Y,
                    style.Width,
                    style.Height,
                    parent,
                    style.Menu,
                    instance,
                    data
                    );
    return result;
}

HWND T100WindowModule::CreateWindowHandler(
    T100Win32Application* application,
    HINSTANCE instance,
    HWND hwnd,
    T100WindowStyle* style,
    T100EventHandler* handler,
    T100VOID* data)
{
    HWND        result      = 0;

    result  = CreateWindowInstance(instance, hwnd, *style, data);
    if(result){
        application->GetWindowMessageDispatcher().RegisterWindowHandler(result, handler);
    }

    return result;
}

}
