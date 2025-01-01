#include "T100ProjectGirder.h"

T100ProjectGirder::T100ProjectGirder()
{
    //ctor
    create();
}

T100ProjectGirder::~T100ProjectGirder()
{
    //dtor
    destroy();
}

T100VOID T100ProjectGirder::create()
{
    m_store = T100NEW T100ProjectStore();
    m_serve = T100NEW T100ProjectServe();
    m_view  = T100NEW T100ProjectView();
}

T100VOID T100ProjectGirder::destroy()
{
    T100SAFE_DELETE m_view;
    T100SAFE_DELETE m_serve;
    T100SAFE_DELETE m_store;
}

T100VOID T100ProjectGirder::setStore(T100ProjectStore* store)
{
    m_store = store;
}

T100ProjectStore* T100ProjectGirder::getStore()
{
    return m_store;
}

T100VOID T100ProjectGirder::setServe(T100ProjectServe* serve)
{
    m_serve = serve;
}

T100ProjectServe* T100ProjectGirder::getServe()
{
    return m_serve;
}

T100VOID T100ProjectGirder::setView(T100ProjectView* view)
{
    m_view  = view;
}

T100ProjectView* T100ProjectGirder::getView()
{
    return m_view;
}
