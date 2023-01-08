#include "T100PainterApp.h"

#include "T100Painter.h"
#include "T100PainterView.h"

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
    T100BOOL    result;

    m_painter   = T100NEW T100Painter(this);
    result = m_painter->create();
    if(!result){
        T100SAFE_DELETE(m_painter);
    }
}

T100VOID T100PainterApp::destroy()
{
    T100SAFE_DELETE(m_painter);
}

T100VOID T100PainterApp::show()
{
    if(m_painter){
        m_painter->show();
        m_painter->NewFile();
    }
}

}
