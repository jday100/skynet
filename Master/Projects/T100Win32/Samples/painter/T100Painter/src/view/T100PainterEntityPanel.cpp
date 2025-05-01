#include "T100PainterEntityPanel.h"

#include "gui/layout/T100FillLayout.h"
#include "gui/listctrl/T100ListItem.h"

T100PainterEntityPanel::T100PainterEntityPanel() :
    T100Panel(),
    m_listCtrl()
{
    //ctor
}

T100PainterEntityPanel::~T100PainterEntityPanel()
{
    //dtor
}

T100VOID T100PainterEntityPanel::Create(T100Window* parent, T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Panel::Create(parent, label, width, height);

    init();
}

T100VOID T100PainterEntityPanel::init()
{
    m_listCtrl.Create(this);

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    this->SetLayoutPtr(layout);

    T100ListItem*       item    = T100NEW T100ListItem(L"Item");

    m_listCtrl.Append(L"Dot");
    m_listCtrl.Append(L"Line");
    m_listCtrl.Append(L"item");
    m_listCtrl.Append(L"item");
    m_listCtrl.Append(L"item");
    m_listCtrl.Append(L"item");
    m_listCtrl.Append(L"item");
}

T100VOID T100PainterEntityPanel::uninit()
{

}
