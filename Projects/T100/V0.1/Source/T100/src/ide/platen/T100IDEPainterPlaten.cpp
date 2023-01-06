#include "T100IDEPainterPlaten.h"

#include "T100PainterElementsPanel.h"
#include "T100PainterView.h"
#include "T100IDEView.h"
#include "T100IDEViewManager.h"
#include "T100IDEPlatenManager.h"

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
    set_menu();
    m_view->getViewManager()->getAuiManager()->Update();

    return T100TRUE;
}

T100Painter::T100PainterElementsPanel* T100IDEPainterPlaten::getElementsPanel()
{
    return m_panel;
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

}
