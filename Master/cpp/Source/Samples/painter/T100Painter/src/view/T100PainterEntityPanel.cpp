#include "T100PainterEntityPanel.h"

#include "gui/T100FillLayout.h"
#include "gui/T100ListItem.h"
#include "gui/T100MessageBox.h"
#include "T100PainterInvoking.h"

T100PainterEntityPanel::T100PainterEntityPanel() :
    T100Panel(),
    m_listView()
{
    //ctor
}

T100PainterEntityPanel::T100PainterEntityPanel(T100Win32Application* app, T100Window* parent) :
    T100Panel(parent),
    m_listView(app, parent)
{
    //ctor
}

T100PainterEntityPanel::~T100PainterEntityPanel()
{
    //dtor
}

T100VOID T100PainterEntityPanel::Create(T100Win32Application* app, T100Window* parent, T100WSTRING label, T100PanelStyle* style)
{
    //T100Panel::Create(app, parent, label, style);
    T100Panel::Create(parent);

    init();
}

T100VOID T100PainterEntityPanel::init()
{
    m_listView.Create((T100Win32Application*)GetApplicationPtr(), this);
    m_listView.Show();

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    this->SetLayout(layout);

    T100ListItem*       item    = T100NEW T100ListItem(L"Item");

    m_listView.Append(L"Dot");
    m_listView.Append(L"Line");
    m_listView.Append(L"item");
    m_listView.Append(L"item");
    m_listView.Append(L"item");
    m_listView.Append(L"item");
    m_listView.Append(L"item");

    m_listView.ConnectNotify(T100EVENT_LISTVIEW_SELECTED, (T100EVENT_FUNCTION)&OnListViewItemSelected, this);
}

T100VOID T100PainterEntityPanel::uninit()
{

}

T100VOID T100PainterEntityPanel::OnListViewItemSelected(T100NotifyEvent& event)
{
    T100WSTRING     value;

    value   = L"Click : ";
    value   += std::to_wstring(event.GetID());

    ShowMessageBox(this, value);

    T100PainterInvoking::EntitySelected(event.GetID());
}
