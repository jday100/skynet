#include "T100FontCallback.h"

namespace T100FontBuilder{

T100FontServe*      T100FontCallback::m_serve           = T100NULL;
T100FontView*       T100FontCallback::m_view            = T100NULL;


T100FontCallback::T100FontCallback()
{
    //ctor
}

T100FontCallback::~T100FontCallback()
{
    //dtor
}

T100VOID T100FontCallback::init(T100FontServe* serve, T100FontView* view)
{
    m_serve     = serve;
    m_view      = view;
}

T100BOOL T100FontCallback::panel_click(T100VOID* d)
{

}

}
