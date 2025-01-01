#include "T100ProjectTextView.h"

IMPLEMENT_DYNAMIC_CLASS(T100ProjectTextView, T100ProjectMDIView)

BEGIN_EVENT_TABLE(T100ProjectTextView, T100ProjectMDIView)
END_EVENT_TABLE()

T100ProjectTextView::T100ProjectTextView()
    :T100ProjectMDIView()
{
    //ctor
    create();
}

T100ProjectTextView::~T100ProjectTextView()
{
    //dtor
    destroy();
}

T100VOID T100ProjectTextView::create()
{

}

T100VOID T100ProjectTextView::destroy()
{

}

T100BOOL T100ProjectTextView::OnCreate(wxDocument* doc, long flags)
{
    if( !wxView::OnCreate(doc, flags) ){
        return T100FALSE;
    }

    return T100TRUE;
}

T100VOID T100ProjectTextView::OnDraw(wxDC* dc)
{

}

T100BOOL T100ProjectTextView::OnClose(T100BOOL deleteWindow)
{
    if( !wxView::OnClose(deleteWindow) ){
        return T100FALSE;
    }

    Activate(T100FALSE);

    return T100TRUE;
}

