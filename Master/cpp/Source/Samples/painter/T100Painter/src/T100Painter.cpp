#include "T100Painter.h"

#include "T100PainterInvoking.h"

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

T100VOID T100Painter::Create(T100Win32Application* app)
{
    init(app);
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

T100VOID T100Painter::init(T100Win32Application* app)
{
    T100PainterInvoking::Create(this);
    m_view.Create(app);
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

T100VOID T100Painter::Select(T100WORD index)
{
    m_serve.Select(index);
}
