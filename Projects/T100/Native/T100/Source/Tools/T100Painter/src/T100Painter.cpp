#include "T100Painter.h"

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"

#include "T100PainterMenuNewThreadTask.h"
#include "T100PainterMenuOpenThreadTask.h"
#include "T100PainterMenuCloseThreadTask.h"
#include "T100PainterMenuSaveThreadTask.h"
#include "T100PainterMenuSaveAsThreadTask.h"
#include "T100PainterMenuQuitThreadTask.h"

#include "T100PainterPanelElementsLoadThreadTask.h"

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
    m_store     = T100NEW T100PainterStore();
    m_serve     = T100NEW T100PainterServe();
    m_view      = T100NEW T100PainterView();

    T100PainterCallback::init(this, m_store, m_serve, m_view);

    m_view->getElementsPanel()->setElementsDrawer(m_serve->getElementsDrawer());

    init();
    New();
}

T100VOID T100Painter::destroy()
{
    T100DELETE  m_view;
    T100DELETE  m_serve;
    T100DELETE  m_store;
}

T100VOID T100Painter::setStore(T100PainterStore* store)
{
    m_store     = store;
}

T100PainterStore* T100Painter::getStore()
{
    return m_store;
}

T100VOID T100Painter::setServe(T100PainterServe* serve)
{
    m_serve     = serve;
}

T100PainterServe* T100Painter::getServe()
{
    return m_serve;
}

T100VOID T100Painter::setView(T100PainterView* view)
{
    m_view      = view;
}

T100PainterView* T100Painter::getView()
{
    return m_view;
}

T100VOID T100Painter::init()
{
    T100PainterPanelElementsLoadThreadTask*         task            = T100NULL;

    task    = T100NEW T100PainterPanelElementsLoadThreadTask();

    task->setPanel(m_view->getElementsPanel());
    task->start();
}

T100BOOL T100Painter::New()
{
    T100BOOL            result;

    if(m_serve->opened()){
        if(m_serve->modified()){
            if(m_serve->getFileName() == L""){

            }else{

            }
        }else{

        }
    }else{

    }




    T100PainterMenuNewThreadTask*           task            = T100NULL;

    task    = T100NEW T100PainterMenuNewThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();

    return T100TRUE;
}

T100BOOL T100Painter::Open()
{
    T100BOOL            result;
    T100STRING          filename;

    result  = m_view->Open(filename);

    if(result){
        T100PainterMenuOpenThreadTask*          task            = T100NULL;

        task    = T100NEW T100PainterMenuOpenThreadTask();

        task->setFileName(filename);
        task->setEvtHandler(m_view->getCanvas());
        task->start();
    }

    return T100TRUE;
}

T100BOOL T100Painter::Close()
{
    T100PainterMenuCloseThreadTask*         task            = T100NULL;

    task    = T100NEW T100PainterMenuCloseThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();

    return T100TRUE;
}

T100BOOL T100Painter::Save()
{
    T100PainterMenuSaveThreadTask*          task            = T100NULL;

    task    = T100NEW T100PainterMenuSaveThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();

    return T100TRUE;
}

T100BOOL T100Painter::SaveAs()
{
    T100BOOL            result;
    T100STRING          filename;

    result  = m_view->SaveAs(filename);


    T100PainterMenuSaveAsThreadTask*        task            = T100NULL;

    task    = T100NEW T100PainterMenuSaveAsThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();

    return T100TRUE;
}

T100BOOL T100Painter::Quit()
{
    T100PainterMenuQuitThreadTask*          task            = T100NULL;

    task    = T100NEW T100PainterMenuQuitThreadTask();

    task->setEvtHandler(m_view->getCanvas());
    task->start();

    return T100TRUE;
}
