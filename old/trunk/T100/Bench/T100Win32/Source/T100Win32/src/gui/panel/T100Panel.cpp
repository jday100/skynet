#include "gui/T100Panel.h"

namespace T100WINDOWS{

T100Panel::T100Panel() :
    T100Window()
{
    //ctor
}

T100Panel::T100Panel(T100Window* parent) :
    T100Window()
{
    //ctor
    m_style     = T100PanelStyle();
    init(parent);
}

T100Panel::~T100Panel()
{
    //dtor
    uninit();
}

T100VOID T100Panel::init(T100Window* parent)
{
    T100Window::Create(parent, &m_style);
}

T100VOID T100Panel::uninit()
{

}

T100VOID T100Panel::Create(T100Window* parent, T100PanelStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100PanelStyle();
    }
    init(parent);
}

T100VOID T100Panel::Destroy()
{
    T100Window::Destroy();
}

}
