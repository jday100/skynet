#include "T100DiskSkeletal.h"

#include "T100DiskApp.h"

T100DiskSkeletal::T100DiskSkeletal() :
    m_view(),
    m_serve(),
    m_store()
{
    //ctor
}

T100DiskSkeletal::~T100DiskSkeletal()
{
    //dtor
}

T100VOID T100DiskSkeletal::Create(T100DiskApp* application)
{
    m_view.Create(application->GetFrame());
}

T100VOID T100DiskSkeletal::Destroy()
{

}
