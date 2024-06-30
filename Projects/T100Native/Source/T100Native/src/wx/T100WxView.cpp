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

T100VOID T100WxView::SetRender(T100RenderBase* render)
{
    m_render    = render;
}

T100RenderBase* T100WxView::GetRender()
{
    return m_render;
}

T100VOID T100WxView::Draw(T100VOID* data)
{
    wxAutoBufferedPaintDC*      dc          = T100NULL;

    dc  = (wxAutoBufferedPaintDC*)data;

    if(dc){
        dc->DrawLine(0, 0, 10, 10);
    }

    for(int m = 0;m < m_height;m++){
        for(int n = 0;n < m_width;n++){
            m_render->Pyramid();
        }
    }
}
