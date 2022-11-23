#include "T100FontApp.h"


namespace T100FontBuilder{

T100FontApp::T100FontApp(T100ThisAppManager* obj)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj)
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

}

T100VOID T100FontApp::destroy()
{

}

T100VOID T100FontApp::show()
{

}

}
