#include "T100Control.h"

#include "gui/T100Win32Application.h"

namespace T100WINDOWS{

T100Control::T100Control() :
    T100Window()
{
    //ctor
}

T100Control::T100Control(T100Window* parent) :
    T100Window()
{
    //ctor
    init(parent);
}

T100Control::~T100Control()
{
    //dtor
    uninit();
}

T100VOID T100Control::init(T100Window* parent)
{
    T100UINT    id      = parent->GetApplication()->GetIDManager().Next();

    m_id            = id;
    m_style.Menu    = (HMENU)id;

    T100Window::Create(parent, &m_style);

    GetApplication()->GetWindowMessageDispatcher().RegisterControlHandler(id, this);
}

T100VOID T100Control::uninit()
{
    T100Window::Destroy();
}

T100VOID T100Control::Create(T100Window* parent, T100WindowStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100WindowStyle();
    }
    init(parent);
}

T100VOID T100Control::Destroy()
{
    T100Window::Destroy();
}

}
