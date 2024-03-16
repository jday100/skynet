#include "T100Painter.h"

T100Painter::T100Painter()
{
    //ctor
    create();
}

T100Painter::~T100Painter()
{
    //dtor
    destroy();
}

T100VOID T100Painter::create()
{
    m_store = T100NEW T100PainterStore();
    m_serve = T100NEW T100PainterServe();
    m_view  = T100NEW T100PainterView();
}

T100VOID T100Painter::destroy()
{
    T100SAFE_DELETE(m_view)
    T100SAFE_DELETE(m_serve)
    T100SAFE_DELETE(m_store)
}

T100VOID T100Painter::setStore(T100PainterStore* store)
{
    m_store = store;
}

T100PainterStore* T100Painter::getStore()
{
    return m_store;
}

T100VOID T100Painter::setServe(T100PainterServe* serve)
{
    m_serve = serve;
}

T100PainterServe* T100Painter::getServe()
{
    return m_serve;
}

T100VOID T100Painter::setView(T100PainterView* view)
{
    m_view  = view;
}

T100PainterView* T100Painter::getView()
{
    return m_view;
}
