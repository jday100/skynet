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
    m_frame = T100NEW T100NativeFrame(0);
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
