#include "T100IDECallback.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"


T100IDEStore*       T100IDECallback::m_store        = T100NULL;
T100IDEServe*       T100IDECallback::m_serve        = T100NULL;
T100IDEView*        T100IDECallback::m_view         = T100NULL;


T100IDECallback::T100IDECallback()
{
    //ctor
}

T100IDECallback::~T100IDECallback()
{
    //dtor
}

T100BOOL T100IDECallback::init(T100IDEStore* store, T100IDEServe* serve, T100IDEView* view)
{
    if(!store)return T100FALSE;
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_store     = store;
    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}
