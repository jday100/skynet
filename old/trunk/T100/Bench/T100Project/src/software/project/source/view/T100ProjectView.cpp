#include "T100ProjectView.h"

#include "T100ProjectMain.h"

T100ProjectView::T100ProjectView()
{
    //ctor
}

T100ProjectView::~T100ProjectView()
{
    //dtor
}

T100VOID T100ProjectView::Create(T100ProjectFrame* frame)
{
    m_frame     = frame;
}

T100VOID T100ProjectView::Destroy()
{
    m_frame->Destroy();
}
