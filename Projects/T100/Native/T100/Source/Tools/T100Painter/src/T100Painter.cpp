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

T100BOOL T100Painter::New()
{
    return T100FALSE;
}

T100BOOL T100Painter::Open()
{
    return T100FALSE;
}

T100BOOL T100Painter::Close()
{
    return T100FALSE;
}

T100BOOL T100Painter::Save()
{
    return T100FALSE;
}

T100BOOL T100Painter::SaveAs()
{
    return T100FALSE;
}

T100BOOL T100Painter::Quit()
{
    return T100FALSE;
}
