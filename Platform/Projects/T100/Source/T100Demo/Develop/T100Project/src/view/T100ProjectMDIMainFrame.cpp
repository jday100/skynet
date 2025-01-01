#include "T100ProjectMDIMainFrame.h"

BEGIN_EVENT_TABLE(T100ProjectMDIMainFrame,wxDocMDIParentFrame)

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
