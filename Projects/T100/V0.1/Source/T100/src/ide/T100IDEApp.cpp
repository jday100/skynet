#include "T100IDEApp.h"

#include "T100IDE.h"

namespace T100IDE{

T100IDEApp::T100IDEApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj, quit)
{
    //ctor
    create();
}

T100IDEApp::~T100IDEApp()
{
    //dtor
    destroy();
}

T100VOID T100IDEApp::create()
{
    m_ide   = T100NEW T100IDE(this);
}

T100VOID T100IDEApp::destroy()
{
    T100SAFE_DELETE(m_ide);
}

T100VOID T100IDEApp::show()
{
    if(m_ide){
        m_ide->show();
    }
}

T100IDEView* T100IDEApp::getView()
{
    if(m_ide){
        return m_ide->getView();
    }
    return T100NULL;
}

}
