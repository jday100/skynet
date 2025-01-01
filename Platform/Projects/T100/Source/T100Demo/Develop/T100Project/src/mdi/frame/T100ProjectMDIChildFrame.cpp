#include "T100ProjectMDIChildFrame.h"

BEGIN_EVENT_TABLE(T100ProjectMDIChildFrame,wxDocMDIChildFrame)

END_EVENT_TABLE()

T100ProjectMDIChildFrame::T100ProjectMDIChildFrame(wxDocument *doc,
                       wxView *view,
                       wxMDIParentFrame *parent,
                       wxWindowID id,
                       const wxString& title,
                       const wxPoint& pos,
                       const wxSize& size,
                       long style,
                       const wxString& name)
    :wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100ProjectMDIChildFrame::~T100ProjectMDIChildFrame()
{
    //dtor
}
