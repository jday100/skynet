#include "T100PainterCallback.h"

#include "T100Painter.h"
#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"

#include "T100ElementInfo.h"

T100Painter*            T100PainterCallback::m_painter                      = T100NULL;
T100PainterStore*       T100PainterCallback::m_store                        = T100NULL;
T100PainterServe*       T100PainterCallback::m_serve                        = T100NULL;
T100PainterView*        T100PainterCallback::m_view                         = T100NULL;

T100PainterCallback::T100PainterCallback()
{
    //ctor
}

T100PainterCallback::~T100PainterCallback()
{
    //dtor
}

T100VOID T100PainterCallback::init(T100Painter* painter, T100PainterStore* store, T100PainterServe* serve, T100PainterView* view)
{
    m_painter   = painter;
    m_store     = store;
    m_serve     = serve;
    m_view      = view;
}

T100Painter* T100PainterCallback::getPainter()
{
    return m_painter;
}

T100PainterStore* T100PainterCallback::getStore()
{
    return m_store;
}

T100PainterServe* T100PainterCallback::getServe()
{
    return m_serve;
}

T100PainterView* T100PainterCallback::getView()
{
    return m_view;
}

T100VOID T100PainterCallback::frame_menu_new(T100VOID* data)
{
    m_painter->New();
}
