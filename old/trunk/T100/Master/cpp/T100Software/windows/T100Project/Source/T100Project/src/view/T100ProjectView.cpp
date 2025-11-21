#include "T100ProjectView.h"

T100ProjectView::T100ProjectView() :
    m_platenManager()
{
    //ctor
}

T100ProjectView::~T100ProjectView()
{
    //dtor
}

T100VOID T100ProjectView::SetFrame(T100Frame* frame)
{
    m_frame     = frame;
}

T100Frame* T100ProjectView::GetFrame()
{
    return m_frame;
}

T100ProjectPlatenManager& T100ProjectView::GetPlatenManager()
{
    return m_platenManager;
}

T100VOID T100ProjectView::Default()
{
    m_platenManager.Update(0);
}
