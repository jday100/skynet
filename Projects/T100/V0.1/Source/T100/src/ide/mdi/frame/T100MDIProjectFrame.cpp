#include "T100MDIProjectFrame.h"

#include "T100TestTools.h"
#include "T100IDEView.h"
#include "T100IDEPlatenManager.h"


namespace T100IDE{

BEGIN_EVENT_TABLE(T100MDIProjectFrame, wxDocMDIChildFrame)
    EVT_SET_FOCUS(T100MDIProjectFrame::OnSetFocus)
END_EVENT_TABLE()

T100MDIProjectFrame::T100MDIProjectFrame(wxDocument *doc, wxView *view, wxMDIParentFrame *parent,
                                wxWindowID id, const wxString& title, const wxPoint& pos,
                                const wxSize& size, long style, const wxString& name)
    :wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name)
{
    //ctor
}

T100MDIProjectFrame::~T100MDIProjectFrame()
{
    //dtor
}

T100VOID T100MDIProjectFrame::setView(T100IDEView* view)
{
    m_view = view;
}

T100VOID T100MDIProjectFrame::setProject(T100PROJECT::T100Project* project)
{
    m_project   = project;
}

void T100MDIProjectFrame::OnSetFocus(wxFocusEvent& event)
{
    T100Library::T100TestTools::Print(L"OnSetFocus");

    m_project->reset();
    m_view->getPlatenManager()->getCurrent()->hide();
    m_view->getPlatenManager()->Change(T100IDE_TYPE_PROJECT);
}

}
