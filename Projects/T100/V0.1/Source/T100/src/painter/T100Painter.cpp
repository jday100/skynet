#include "T100Painter.h"

#include "T100PainterServe.h"
#include "T100PainterView.h"

namespace T100Painter{

T100Painter::T100Painter(T100PainterApp* app)
    :m_app(app)
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
    m_serve     = T100NEW T100PainterServe();
    m_view      = T100NEW T100PainterView();
}

T100VOID T100Painter::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100VOID T100Painter::setServe(T100PainterServe* serve)
{

}

T100PainterServe* T100Painter::getServe()
{

}

T100VOID T100Painter::setView(T100PainterView* view)
{

}

T100PainterView* T100Painter::getView()
{

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

}
