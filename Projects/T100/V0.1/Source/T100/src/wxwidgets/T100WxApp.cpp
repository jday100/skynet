#include "T100WxApp.h"

namespace T100WxWidgets{

T100WxApp::T100WxApp(T100WxAppManager* obj, T100BOOL quit)
    :T100Library::T100AppBase((T100Library::T100AppManager*)obj, quit)
{
    //ctor
}

T100WxApp::~T100WxApp()
{
    //dtor
}

}
