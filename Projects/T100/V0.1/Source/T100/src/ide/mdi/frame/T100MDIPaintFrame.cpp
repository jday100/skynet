#include "T100MDIPaintFrame.h"

#include "T100TestTools.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100MDIPaintFrame, wxDocMDIChildFrame)
    EVT_SET_FOCUS(T100MDIPaintFrame::OnSetFocus)
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

T100VOID T100MDIPaintFrame::setPainter(T100Painter::T100Painter* painter)
{
    m_painter = painter;
}

void T100MDIPaintFrame::OnSetFocus(wxFocusEvent& event)
{
    T100Library::T100TestTools::Print(L"OnSetFocus");

    m_painter->reset();
}

}
