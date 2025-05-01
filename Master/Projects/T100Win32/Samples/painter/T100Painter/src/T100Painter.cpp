#include "T100Painter.h"

T100Painter::T100Painter() :
    m_store(),
    m_serve(),
    m_view()
{
    //ctor
}

T100Painter::~T100Painter()
{
    //dtor
    uninit();
}

T100VOID T100Painter::Create()
{
    init();
}

T100PainterStore& T100Painter::GetStore()
{
    return m_store;
}

T100PainterServe& T100Painter::GetServe()
{
    return m_serve;
}

T100PainterView& T100Painter::GetView()
{
    return m_view;
}

T100VOID T100Painter::init()
{
    m_view.Create();
}

T100VOID T100Painter::uninit()
{
    m_view.Destroy();
}

T100VOID T100Painter::New()
{

}

T100VOID T100Painter::Quit()
{
    PostQuitMessage(0);
}

T100VOID T100Painter::Resize()
{
    m_view.GetDockManager().Update();
}
