#include "T100MDITextView.h"

namespace T100IDE{

IMPLEMENT_DYNAMIC_CLASS(T100MDITextView, wxView)

BEGIN_EVENT_TABLE(T100MDITextView, wxView)
END_EVENT_TABLE()


T100MDITextView::T100MDITextView()
{
    //ctor
}

T100MDITextView::~T100MDITextView()
{
    //dtor
}

T100VOID T100MDITextView::OnDraw(wxDC* dc)
{

}

}
