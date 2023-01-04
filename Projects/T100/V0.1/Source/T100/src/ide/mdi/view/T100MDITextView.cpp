#include "T100MDITextView.h"

#include <wx/stockitem.h>
#include "T100App.h"
#include "T100IDEApp.h"
#include "T100IDEView.h"
#include "T100Editor.h"
#include "T100EditorView.h"

namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDITextView, T100MDIViewBase)

BEGIN_EVENT_TABLE(T100MDITextView, T100MDIViewBase)
END_EVENT_TABLE()


T100MDITextView::T100MDITextView()
    :T100MDIViewBase()
{
    //ctor
    create();
}

T100MDITextView::~T100MDITextView()
{
    //dtor
    destroy();
}

T100VOID T100MDITextView::create()
{

}

T100VOID T100MDITextView::destroy()
{

}

T100BOOL T100MDITextView::OnCreate(wxDocument* doc, long flags)
{
    if( !wxView::OnCreate(doc, flags) ){
        return T100FALSE;
    }

    m_view = wxGetApp().getManager()->getIDE()->getView();

    m_frame = T100NEW T100MDITextFrame(doc, this, wxStaticCast(m_view->getFrame(), wxMDIParentFrame));
    wxASSERT(m_frame == GetFrame());

    m_editor    = T100NEW T100Editor::T100Editor();
    m_editor->getView()->setParent(m_frame);
    m_editor->getView()->create();

    m_frame->Show();

    return T100TRUE;
}

T100VOID T100MDITextView::OnDraw(wxDC* dc)
{

}

T100BOOL T100MDITextView::OnClose(T100BOOL deleteWindow)
{
    if( !wxView::OnClose(deleteWindow) ){
        return T100FALSE;
    }

    Activate(T100FALSE);

    if( deleteWindow ){
        GetFrame()->Destroy();
        SetFrame(T100NULL);
    }

    return T100TRUE;
}

T100Editor::T100Editor* T100MDITextView::GetEditor() const
{
    return m_editor;
}

}
