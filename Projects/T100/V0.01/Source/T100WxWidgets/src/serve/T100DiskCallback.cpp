#include "T100DiskCallback.h"
#include "T100DiskServe.h"
#include "T100DiskView.h"

T100DiskServe*      T100DiskCallback::m_serve               = T100NULL;
T100DiskView*       T100DiskCallback::m_view                = T100NULL;


T100DiskCallback::T100DiskCallback()
{
    //ctor
}

T100DiskCallback::~T100DiskCallback()
{
    //dtor
}

T100BOOL T100DiskCallback::init(T100DiskServe* serve, T100DiskView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}
