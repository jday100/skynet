#include "T100FireView.h"

T100FireView::T100FireView()
{
    //ctor
    TurnOn();
}

T100FireView::~T100FireView()
{
    //dtor
    TurnOff();
}

T100VOID T100FireView::TurnOn()
{
    m_frame     = T100NEW T100NativeFrame(0);
    m_render    = T100NEW T100FireRender(m_frame, wxID_ANY);

    m_frame->SetRender(m_render);
}

T100VOID T100FireView::TurnOff()
{
    T100SAFE_DELETE(m_frame)
}

T100VOID T100FireView::Show()
{
    if(m_frame){
        m_frame->Show();
    }
}

T100NativeFrame* T100FireView::GetFrame()
{
    if(m_frame){
        return m_frame;
    }
    return T100NULL;
}

T100FireRender* T100FireView::GetRender()
{
    if(m_render){
        return m_render;
    }
    return T100NULL;
}
