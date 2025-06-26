#include "gui/T100Button.h"

namespace T100WINDOWS{

T100Button::T100Button() :
    T100Control()
{
    //ctor
}

T100Button::T100Button(T100Window* parent, const T100WSTRING& label) :
    T100Control()
{
    //ctor
    m_style     = T100ButtonStyle();
    init(parent, label);
}

T100Button::~T100Button()
{
    //dtor
    uninit();
}

T100VOID T100Button::init(T100Window* parent, const T100WSTRING& label)
{
    m_style.WindowLabel     = label;
    T100Control::Create(parent, &m_style);
}

T100VOID T100Button::uninit()
{

}

T100VOID T100Button::Create(T100Window* parent, const T100WSTRING& label, T100ButtonStyle* style)
{
    if(style){
        m_style     = *style;
    }else{
        m_style     = T100ButtonStyle();
    }
    init(parent, label);
}

T100VOID T100Button::Destroy()
{
    T100Control::Destroy();
}

}
