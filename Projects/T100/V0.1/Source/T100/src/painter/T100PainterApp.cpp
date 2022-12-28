#include "T100PainterApp.h"

#include "T100Painter.h"

namespace T100Painter{

T100PainterApp::T100PainterApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj, quit)
{
    //ctor
    create();
}

T100PainterApp::~T100PainterApp()
{
    //dtor
    destroy();
}

T100VOID T100PainterApp::create()
{
    m_painter   = T100NEW T100Painter(this);
}

T100VOID T100PainterApp::destroy()
{
    T100SAFE_DELETE(m_painter);
}

T100VOID T100PainterApp::show()
{
    if(m_painter){
        m_painter->show();
    }
}

}
