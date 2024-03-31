#include "T100WPainter.h"

#include "T100WPainterStore.h"
#include "T100WPainterServe.h"
#include "T100WPainterView.h"
#include "T100WPainterCallback.h"

#include "T100WPainterMenuNewThreadTask.h"
#include "T100WPainterMenuOpenThreadTask.h"
#include "T100WPainterMenuSaveThreadTask.h"
#include "T100WPainterMenuSaveAsThreadTask.h"

T100WPainter::T100WPainter()
{
    //ctor
    create();
}

T100WPainter::~T100WPainter()
{
    //dtor
    destroy();
}

T100VOID T100WPainter::create()
{
    m_store     = T100NEW T100WPainterStore();
    m_serve     = T100NEW T100WPainterServe();
    m_view      = T100NEW T100WPainterView();

    T100WPainterCallback::init(this, m_store, m_serve, m_view);

    New();
}

T100VOID T100WPainter::destroy()
{
    T100DELETE  m_view;
    T100DELETE  m_serve;
    T100DELETE  m_store;
}

T100VOID T100WPainter::setStore(T100WPainterStore* store)
{
    m_store     = store;
}

T100WPainterStore* T100WPainter::getStore()
{
    return m_store;
}

T100VOID T100WPainter::setServe(T100WPainterServe* serve)
{
    m_serve     = serve;
}

T100WPainterServe* T100WPainter::getServe()
{
    return m_serve;
}

T100VOID T100WPainter::setView(T100WPainterView* view)
{
    m_view      = view;
}

T100WPainterView* T100WPainter::getView()
{
    return m_view;
}

T100BOOL T100WPainter::New()
{
    T100WPainterMenuNewThreadTask*          task            = T100NULL;

    task    = T100NEW T100WPainterMenuNewThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();
}

T100BOOL T100WPainter::Open()
{
    m_view->Open();

    T100WPainterMenuOpenThreadTask*         task            = T100NULL;

    task    = T100NEW T100WPainterMenuOpenThreadTask();

    task->start();
}

T100BOOL T100WPainter::Close()
{

}

T100BOOL T100WPainter::Save()
{
    T100WPainterMenuSaveThreadTask*         task            = T100NULL;

    task    = T100NEW T100WPainterMenuSaveThreadTask();

    task->start();
}

T100BOOL T100WPainter::SaveAs()
{
    T100STRING      filename;

    m_view->SaveAs(filename);

    T100WPainterMenuSaveAsThreadTask*       task            = T100NULL;

    task    = T100NEW T100WPainterMenuSaveAsThreadTask();

    task->setFileName(filename);
    task->start();
}

T100BOOL T100WPainter::Quit()
{

}
