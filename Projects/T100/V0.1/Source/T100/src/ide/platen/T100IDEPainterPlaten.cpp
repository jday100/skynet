#include "T100IDEPainterPlaten.h"

#include "T100PainterElementsPanel.h"
#include "T100PainterView.h"
#include "T100IDEView.h"
#include "T100IDEViewManager.h"

namespace T100IDE{

T100IDEPainterPlaten::T100IDEPainterPlaten(T100IDEView* view, void* data)
    :T100IDEPlatenBase(view), m_data(data)
{
    //ctor
}

T100IDEPainterPlaten::~T100IDEPainterPlaten()
{
    //dtor
}

T100BOOL T100IDEPainterPlaten::create()
{
    m_painter   = static_cast<T100Painter::T100Painter*>(m_data);
    if(!m_painter)return T100FALSE;

    m_panel   = m_painter->getView()->getElementsPanel();
    if(!m_panel)return T100FALSE;

    m_view->getViewManager()->getAuiManager()->AddPane(m_panel, wxAuiPaneInfo().Name(wxT("Name")).DefaultPane().Left());
    m_view->getViewManager()->getAuiManager()->Update();

    return T100TRUE;
}

T100VOID T100IDEPainterPlaten::destroy()
{

}

T100BOOL T100IDEPainterPlaten::show()
{
    m_view->getViewManager()->getAuiManager()->Update();

    return T100TRUE;
}

T100Painter::T100PainterElementsPanel* T100IDEPainterPlaten::getElementsPanel()
{
    return m_panel;
}

}
