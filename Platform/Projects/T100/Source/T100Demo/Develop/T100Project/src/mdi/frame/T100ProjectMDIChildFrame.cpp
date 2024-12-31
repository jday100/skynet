#include "T100ProjectMDIChildFrame.h"

BEGIN_EVENT_TABLE(T100ProjectMDIChildFrame,wxMDIChildFrame)

END_EVENT_TABLE()

T100ProjectMDIChildFrame::T100ProjectMDIChildFrame(wxMDIParentFrame *parent,
                    wxWindowID id,
                    const wxString& title,
                    const wxPoint& pos,
                    const wxSize& size,
                    long style,
                    const wxString& name)
    :wxMDIChildFrame(parent, id, title, pos, size, style, name)
{
    //ctor
}

T100ProjectMDIChildFrame::~T100ProjectMDIChildFrame()
{
    //dtor
}
