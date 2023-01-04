#include "T100IDEMainFrame.h"

#include "T100IDEViewManager.h"

#include "T100TestTools.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100IDEMainFrame, wxDocMDIParentFrame)
    EVT_SIZE(T100IDEMainFrame::OnResize)
END_EVENT_TABLE()

T100IDEMainFrame::T100IDEMainFrame(wxDocManager *manager, wxFrame *parent, wxWindowID id,
                            const wxString& title, const wxPoint& pos, const wxSize& size,
                            long style, const wxString& name)
    :wxDocMDIParentFrame(manager, parent, id, title, pos, size, style, name)
{
    //ctor
    create();
}

T100IDEMainFrame::~T100IDEMainFrame()
{
    //dtor
    destroy();
}

T100VOID T100IDEMainFrame::create()
{
    //Connect(wxID_RESIZE_FRAME, wxEVT_SIZE, (wxObjectEventFunction)&T100IDEMainFrame::OnResize);
}

T100VOID T100IDEMainFrame::destroy()
{

}

T100VOID T100IDEMainFrame::setView(T100IDEView* view)
{
    m_view = view;
}

T100IDEView* T100IDEMainFrame::getView()
{
    return m_view;
}

void T100IDEMainFrame::OnResize(wxSizeEvent& event)
{
    T100Library::T100TestTools::Print(L"OnResize");
    m_view->getViewManager()->getAuiManager()->Update();

    event.Skip();
}

}
