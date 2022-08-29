#include "T100FontCallback.h"

#include "T100FontServe.h"
#include "T100FontView.h"

T100FontServe*          T100FontCallback::m_serve           = T100NULL;
T100FontView*           T100FontCallback::m_view            = T100NULL;


T100FontCallback::T100FontCallback()
{
    //ctor
}

T100FontCallback::~T100FontCallback()
{
    //dtor
}

T100BOOL T100FontCallback::init(T100FontServe* serve, T100FontView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}

T100BOOL T100FontCallback::panel_click(T100VOID* v)
{

}
