#include "T100ProjectMDIMainFrame.h"

BEGIN_EVENT_TABLE(T100ProjectMDIMainFrame,wxMDIParentFrame)

END_EVENT_TABLE()

T100ProjectMDIMainFrame::T100ProjectMDIMainFrame(wxWindow *parent,
                     wxWindowID id,
                     const wxString& title,
                     const wxPoint& pos,
                     const wxSize& size,
                     long style,
                     const wxString& name)
    :wxMDIParentFrame(parent, id, title, pos, size, style, name)
{
    //ctor
}

T100ProjectMDIMainFrame::~T100ProjectMDIMainFrame()
{
    //dtor
}
