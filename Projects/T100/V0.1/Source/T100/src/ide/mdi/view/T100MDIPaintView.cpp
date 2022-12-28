#include "T100MDIPaintView.h"

#include <wx/stockitem.h>
#include "T100App.h"
#include "T100IDEApp.h"
#include "T100IDEView.h"
#include "T100Painter.h"
#include "T100PainterView.h"

namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDIPaintView, wxView)

BEGIN_EVENT_TABLE(T100MDIPaintView, wxView)
END_EVENT_TABLE()


T100MDIPaintView::T100MDIPaintView()
{
    //ctor
    create();
}

T100MDIPaintView::~T100MDIPaintView()
{
    //dtor
    destroy();
}

T100VOID T100MDIPaintView::create()
{

}

T100VOID T100MDIPaintView::destroy()
{

}

T100BOOL T100MDIPaintView::OnCreate(wxDocument* doc, long flags)
{
    if( !wxView::OnCreate(doc, flags) ){
        return T100FALSE;
    }

    m_view = wxGetApp().getManager()->getIDE()->getView();

    m_frame = T100NEW T100MDIPaintFrame(doc, this, wxStaticCast(m_view->getFrame(), wxMDIParentFrame));
    wxASSERT(m_frame == GetFrame());

    m_painter   = T100NEW T100Painter::T100Painter();
    m_painter->getView()->setParent(m_frame);
    m_painter->getView()->create();

    m_frame->Show();

    return T100TRUE;
}

T100VOID T100MDIPaintView::OnDraw(wxDC* dc)
{

}

T100BOOL T100MDIPaintView::OnClose(T100BOOL deleteWindow)
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

T100Painter::T100Painter* T100MDIPaintView::GetPainter() const
{
    return m_painter;
}

}
