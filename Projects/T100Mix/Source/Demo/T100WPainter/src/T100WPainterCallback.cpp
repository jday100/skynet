#include "T100WPainterCallback.h"

#include "T100WPainter.h"
#include "T100WPainterStore.h"
#include "T100WPainterServe.h"
#include "T100WPainterView.h"

#include "T100ElementInfo.h"

T100WPainter*           T100WPainterCallback::m_painter                 = T100NULL;
T100WPainterStore*      T100WPainterCallback::m_store                   = T100NULL;
T100WPainterServe*      T100WPainterCallback::m_serve                   = T100NULL;
T100WPainterView*       T100WPainterCallback::m_view                    = T100NULL;

T100WPainterCallback::T100WPainterCallback()
{
    //ctor
}

T100WPainterCallback::~T100WPainterCallback()
{
    //dtor
}

T100VOID T100WPainterCallback::init(T100WPainter* painter, T100WPainterStore* store, T100WPainterServe* serve, T100WPainterView* view)
{
    m_painter       = painter;
    m_store         = store;
    m_serve         = serve;
    m_view          = view;
}

T100WPainter* T100WPainterCallback::getPainter()
{
    return m_painter;
}

T100WPainterStore* T100WPainterCallback::getStore()
{
    return m_store;
}

T100WPainterServe* T100WPainterCallback::getServe()
{
    return m_serve;
}

T100WPainterView* T100WPainterCallback::getView()
{
    return m_view;
}

T100VOID T100WPainterCallback::frame_menu_new(T100VOID* data)
{

}

T100VOID T100WPainterCallback::frame_menu_open(T100VOID* data)
{
    m_painter->Open();
}

T100VOID T100WPainterCallback::frame_menu_save(T100VOID* data)
{

}

T100VOID T100WPainterCallback::frame_menu_save_as(T100VOID* data)
{
    m_painter->SaveAs();
}

T100VOID T100WPainterCallback::frame_menu_close(T100VOID* data)
{

}

T100VOID T100WPainterCallback::frame_menu_quit(T100VOID* data)
{

}

T100VOID T100WPainterCallback::elements_item_select(T100VOID* data)
{
    T100ElementInfo*        info            = T100NULL;

    info    = (T100ElementInfo*)data;

    m_view->getFrame()->getCanvas()->Change(T100CANVAS_STATE_PAINT);
}
