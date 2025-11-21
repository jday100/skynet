#include "T100CVMSkeletal.h"

#include "T100CVMApp.h"

T100CVMSkeletal::T100CVMSkeletal() :
    m_view(),
    m_serve(),
    m_store()
{
    //ctor
}

T100CVMSkeletal::~T100CVMSkeletal()
{
    //dtor
}

T100VOID T100CVMSkeletal::Create(T100CVMApp* application)
{
    m_view.Create(application->GetFrame());
}

T100VOID T100CVMSkeletal::Destroy()
{

}

T100VOID T100CVMSkeletal::Start()
{

}

T100VOID T100CVMSkeletal::Stop()
{

}
