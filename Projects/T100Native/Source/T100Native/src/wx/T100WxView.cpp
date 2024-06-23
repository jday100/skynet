#include "T100WxView.h"

#include <wx/dcbuffer.h>

T100WxView::T100WxView()
    :T100ViewBase()
{
    //ctor
}

T100WxView::~T100WxView()
{
    //dtor
}

T100VOID T100WxView::Draw(T100VOID* data)
{
    wxAutoBufferedPaintDC*      dc          = T100NULL;

    dc  = (wxAutoBufferedPaintDC*)data;

    if(dc){
        dc->DrawLine(0, 0, 10, 10);
    }
}
