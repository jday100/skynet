#include "T100FontPanel.h"

T100FontPanel::T100FontPanel() :
    T100Panel()
{
    //ctor
}

T100FontPanel::~T100FontPanel()
{
    //dtor
}

T100VOID T100FontPanel::init()
{

}

T100VOID T100FontPanel::uninit()
{

}

T100VOID T100FontPanel::Create(T100Window* parent, T100PanelStyle* style)
{
    T100Panel::Create(parent, style);
    init();
}

T100VOID T100FontPanel::Destroy()
{

}
