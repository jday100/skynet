#include "T100ProjectMDIMainFrame.h"

#include "T100ProjectViewManager.h"

BEGIN_EVENT_TABLE(T100ProjectMDIMainFrame,wxDocMDIParentFrame)
    EVT_SIZE(T100ProjectMDIMainFrame::OnResize)

    EVT_CLOSE(T100ProjectMDIMainFrame::OnClose)
END_EVENT_TABLE()

T100ProjectMDIMainFrame::T100ProjectMDIMainFrame(wxDocManager *manager,
                        wxFrame *parent,
                        wxWindowID id,
                        const wxString& title,
                        const wxPoint& pos,
                        const wxSize& size,
                        long style,
                        const wxString& name)
    :wxDocMDIParentFrame(manager, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100ProjectMDIMainFrame::~T100ProjectMDIMainFrame()
{
    //dtor
}

T100VOID T100ProjectMDIMainFrame::setView(T100ProjectView* view)
{
    m_view  = view;
}

void T100ProjectMDIMainFrame::OnResize(wxSizeEvent& event)
{
    m_view->getViewManager()->getAuiManager()->Update();
}

void T100ProjectMDIMainFrame::OnClose(wxCloseEvent& event)
{
    m_view->close();
}
