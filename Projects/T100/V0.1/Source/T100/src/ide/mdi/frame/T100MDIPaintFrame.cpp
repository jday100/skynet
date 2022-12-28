#include "T100MDIPaintFrame.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100MDIPaintFrame, wxDocMDIChildFrame)

END_EVENT_TABLE()

T100MDIPaintFrame::T100MDIPaintFrame(wxDocument *doc, wxView *view, wxMDIParentFrame *parent,
                                wxWindowID id, const wxString& title, const wxPoint& pos,
                                const wxSize& size, long style, const wxString& name)
    :wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100MDIPaintFrame::~T100MDIPaintFrame()
{
    //dtor
}

}
