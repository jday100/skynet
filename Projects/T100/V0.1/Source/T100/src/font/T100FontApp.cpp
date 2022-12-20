#include "T100FontApp.h"

#include "T100FontBuilder.h"


namespace T100FontBuilder{

T100FontApp::T100FontApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj, quit)
{
    //ctor
    create();
}

T100FontApp::~T100FontApp()
{
    //dtor
    destroy();
}

T100VOID T100FontApp::create()
{
    m_builder = T100NEW T100FontBuilder(this);
}

T100VOID T100FontApp::destroy()
{
    T100SAFE_DELETE(m_builder);
}

T100FontBuilder* T100FontApp::getFontBuilder()
{
    return m_builder;
}

T100VOID T100FontApp::show()
{
    if(m_builder){
        m_builder->show();
    }
}

}
