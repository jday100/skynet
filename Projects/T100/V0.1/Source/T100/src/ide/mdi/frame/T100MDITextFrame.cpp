#include "T100MDITextFrame.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100MDITextFrame, wxDocMDIChildFrame)

END_EVENT_TABLE()

T100MDITextFrame::T100MDITextFrame(wxDocument *doc, wxView *view, wxMDIParentFrame *parent,
                                wxWindowID id, const wxString& title, const wxPoint& pos,
                                const wxSize& size, long style, const wxString& name)
    :wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100MDITextFrame::~T100MDITextFrame()
{
    //dtor
}

}
