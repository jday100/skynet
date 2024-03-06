#include "T100Painter.h"

#include "T100PainterStore.h"
#include "T100PainterServe.h"
#include "T100PainterView.h"
#include "T100PainterCallback.h"


namespace T100Painter{

T100Painter::T100Painter(T100PainterApp* app)
    :m_app(app)
{
    //ctor
}

T100Painter::~T100Painter()
{
    //dtor
    destroy();
}

T100BOOL T100Painter::create()
{
    m_store     = T100NEW T100PainterStore();
    m_serve     = T100NEW T100PainterServe();
    m_view      = T100NEW T100PainterView();

    m_view->setParent(m_parent);
    m_view->setRootFrame(m_root);

    T100PainterCallback::init(m_store, m_serve, m_view);

    if(m_parent){
        m_transverter.Change(T100PAINTER_STATE_EMBED);
    }else{
        m_transverter.Change(T100PAINTER_STATE_ALONE);
    }

    return m_transverter.GetCurrent()->Create();
}

T100VOID T100Painter::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
    T100SAFE_DELETE(m_store);
}

T100VOID T100Painter::reset()
{
    T100PainterCallback::init(m_store, m_serve, m_view);
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
    m_view = view;
}

T100PainterView* T100Painter::getView()
{
    return m_view;
}

T100VOID T100Painter::show()
{
    if(m_view){
        m_view->show();
    }
}

T100VOID T100Painter::quit()
{

}

T100VOID T100Painter::NewFile()
{
    T100PainterCallback::frame_menu_new();
}

T100PainterState* T100Painter::getCurrent()
{
    return m_transverter.GetCurrent();
}

T100VOID T100Painter::setParent(wxFrame* parent)
{
    m_parent = parent;
}

T100VOID T100Painter::setRootFrame(wxMDIParentFrame* root)
{
    m_root = root;
}

}
