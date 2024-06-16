#include "T100Fire.h"

T100Fire::T100Fire()
    :T100Game()
{
    //ctor
    TurnOn();
}

T100Fire::~T100Fire()
{
    //dtor
    TurnOff();
}

T100VOID T100Fire::TurnOn()
{
    m_store     = T100NEW T100FireStore();
    m_serve     = T100NEW T100FireServe();
    m_view      = T100NEW T100FireView();
}

T100VOID T100Fire::TurnOff()
{
    T100SAFE_DELETE(m_view)
    T100SAFE_DELETE(m_serve)
    T100SAFE_DELETE(m_store)
}

T100VOID T100Fire::Show()
{
    if(m_view){
        m_view->Show();
    }
}

T100NativeFrame* T100Fire::GetFrame()
{
    if(m_view){
        return m_view->GetFrame();
    }
    return T100NULL;
}
