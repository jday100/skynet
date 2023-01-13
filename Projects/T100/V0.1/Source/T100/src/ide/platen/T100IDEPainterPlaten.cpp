#include "T100IDEPainterPlaten.h"

#include "T100PainterElementsPanel.h"
#include "T100PainterView.h"
#include "T100IDEView.h"
#include "T100IDEViewManager.h"
#include "T100IDEPlatenManager.h"

namespace T100IDE{

T100IDEPainterPlaten::T100IDEPainterPlaten(T100IDEView* view)
    :T100IDEPlatenBase(view)
{
    //ctor
}

T100IDEPainterPlaten::~T100IDEPainterPlaten()
{
    //dtor
}

T100BOOL T100IDEPainterPlaten::create()
{
    if(!m_painter)return T100FALSE;

    m_elements_panel    = m_painter->getView()->getElementsPanel();
    if(!m_elements_panel)return T100FALSE;

    m_view->getViewManager()->getAuiManager()->AddPane(m_elements_panel, wxAuiPaneInfo().Name(wxT("Elements")).DefaultPane().Left());

    m_properties_panel  = m_painter->getView()->getPropertiesPanel();
    if(!m_properties_panel)return T100FALSE;

    m_view->getViewManager()->getAuiManager()->AddPane(m_properties_panel, wxAuiPaneInfo().Name(wxT("Properties")).DefaultPane().Left());

    m_view->getViewManager()->getAuiManager()->Update();

    return T100TRUE;
}

T100VOID T100IDEPainterPlaten::destroy()
{

}

T100BOOL T100IDEPainterPlaten::show()
{
    set_menu();

    m_view->getViewManager()->getAuiManager()->GetPane(m_elements_panel).Show();
    m_view->getViewManager()->getAuiManager()->GetPane(m_properties_panel).Show();

    m_view->getViewManager()->getAuiManager()->Update();

    return T100TRUE;
}

T100BOOL T100IDEPainterPlaten::hide()
{

    m_view->getViewManager()->getAuiManager()->GetPane(m_elements_panel).Hide();
    m_view->getViewManager()->getAuiManager()->GetPane(m_properties_panel).Hide();

    m_view->getViewManager()->getAuiManager()->Update();
    return T100TRUE;
}

T100Painter::T100PainterElementsPanel* T100IDEPainterPlaten::getElementsPanel()
{
    return m_elements_panel;
}

T100Painter::T100PainterPropertiesPanel* T100IDEPainterPlaten::getPropertiesPanel()
{
    return m_properties_panel;
}

T100VOID T100IDEPainterPlaten::set_menu()
{
    /*
    wxMDIParentFrame*       frame           = T100NULL;
    wxMenuBar*              menuBar         = T100NULL;

    frame   = wxStaticCast(m_view->getFrame(), wxMDIParentFrame);
    if(!frame)return;

    menuBar = m_view->getPlatenManager()->getDefault()->CreateMainMenuBar();
    if(!menuBar)return;

    menuBar->GetMenu(0)->InsertSeparator(1);

    frame->SetMenuBar(menuBar);
    */

    wxMDIParentFrame*       frame           = T100NULL;
    wxMenuBar*              menuBar         = T100NULL;

    frame   = wxStaticCast(m_view->getFrame(), wxMDIParentFrame);
    if(!frame)return;

    menuBar = frame->GetMenuBar();

    menuBar->GetMenu(0)->InsertSeparator(2);

    menuBar->GetMenu(0)->Insert(3, wxID_SAVE);
    menuBar->GetMenu(0)->Insert(4, wxID_SAVEAS);
    menuBar->GetMenu(0)->Insert(5, wxID_CLOSE);

}

T100VOID T100IDEPainterPlaten::setPainter(T100Painter::T100Painter* painter)
{
    m_painter = painter;
}

}
