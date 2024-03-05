#include "T100ProjectCallback.h"

#include <wx/log.h>

#include "T100ProjectStore.h"
#include "T100ProjectServe.h"
#include "T100ProjectView.h"

namespace T100PROJECT{

T100ProjectStore*       T100ProjectCallback::m_store            = T100NULL;
T100ProjectServe*       T100ProjectCallback::m_serve            = T100NULL;
T100ProjectView*        T100ProjectCallback::m_view             = T100NULL;

T100Component::T100ProjectTransverter           T100ProjectCallback::m_manager;

T100ProjectCallback::T100ProjectCallback()
{
    //ctor
}

T100ProjectCallback::~T100ProjectCallback()
{
    //dtor
}


T100VOID T100ProjectCallback::init(T100ProjectStore* store, T100ProjectServe* serve, T100ProjectView* view)
{
    m_store     = store;
    m_serve     = serve;
    m_view      = view;
}

T100ProjectStore* T100ProjectCallback::getStore()
{
    return m_store;
}

T100ProjectServe* T100ProjectCallback::getServe()
{
    return m_serve;
}

T100ProjectView* T100ProjectCallback::getView()
{
    return m_view;
}

}
