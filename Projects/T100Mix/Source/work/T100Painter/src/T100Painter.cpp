#include "T100Painter.h"

#include "T100PainterCallback.h"
#include "wx\paint\task\T100WxPaintFileLoadThreadTask.h"

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

    T100PainterCallback::init(this, m_store, m_serve, m_view);
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

T100BOOL T100Painter::Opened()
{
    return T100FALSE;
}

T100BOOL T100Painter::New()
{
    T100BOOL            result;

    result  = m_serve->Opened();
    if(result){
        if(m_serve->Modified()){
            result  = m_store->Save();
            if(result){

            }else{
                return T100FALSE;
            }
        }else{

        }

        if(result){
            result  = m_serve->Clear();
        }
    }else{
        return T100TRUE;
    }
    return result;
}

T100BOOL T100Painter::Open()
{
    T100BOOL            result;

    result  = m_view->Open();

    result  = m_store->OpenFile();

    T100WxPaintFileLoadThreadTask*      task        = T100NEW T100WxPaintFileLoadThreadTask();

    task->setWindow(m_view->getFrame());
    task->start();
}

T100BOOL T100Painter::Close()
{

}

T100BOOL T100Painter::Save()
{

}

T100BOOL T100Painter::SaveAs()
{

}

T100BOOL T100Painter::Quit()
{

}
