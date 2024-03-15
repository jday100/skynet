#include "T100WxApp.h"

T100WxApp::T100WxApp()
    :T100App()
{
    //ctor
    create();
}

T100WxApp::~T100WxApp()
{
    //dtor
    destroy();
}

T100VOID T100WxApp::create()
{

}

T100VOID T100WxApp::destroy()
{

}

T100VOID T100WxApp::setStore(T100WxStore* store)
{
    m_store     = store;
}

T100WxStore* T100WxApp::getStore()
{
    return m_store;
}

T100VOID T100WxApp::setServe(T100WxServe* serve)
{
    m_serve     = serve;
}

T100WxServe* T100WxApp::getServe()
{
    return m_serve;
}

T100VOID T100WxApp::setView(T100WxView* view)
{
    m_view      = view;
}

T100WxView* T100WxApp::getView()
{
    return m_view;
}
