#include "T100MDITextFrame.h"

#include "T100IDEView.h"
#include "T100IDEPlatenManager.h"

namespace T100IDE{

BEGIN_EVENT_TABLE(T100MDITextFrame, wxDocMDIChildFrame)
    EVT_SET_FOCUS(T100MDITextFrame::OnSetFocus)
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

T100VOID T100MDITextFrame::setView(T100IDEView* view)
{
    m_view = view;
}

T100VOID T100MDITextFrame::setEditor(T100Editor::T100Editor* editor)
{
    m_editor = editor;
}

void T100MDITextFrame::OnSetFocus(wxFocusEvent& event)
{
    m_editor->Reset();
    m_view->getPlatenManager()->getCurrent()->hide();
    m_view->getPlatenManager()->Change(T100IDE_TYPE_EDITOR);
}

}
