#include "T100IDEMainFrame.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100IDEMainFrame, wxDocMDIParentFrame)

END_EVENT_TABLE()

T100IDEMainFrame::T100IDEMainFrame(wxDocManager *manager, wxFrame *parent, wxWindowID id,
                            const wxString& title, const wxPoint& pos, const wxSize& size,
                            long style, const wxString& name)
    :wxDocMDIParentFrame(manager, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100IDEMainFrame::~T100IDEMainFrame()
{
    //dtor
}

T100VOID T100IDEMainFrame::setView(T100IDEView* view)
{
    m_view = view;
}

T100IDEView* T100IDEMainFrame::getView()
{
    return m_view;
}

}
