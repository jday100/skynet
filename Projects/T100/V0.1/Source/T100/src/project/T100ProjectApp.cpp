#include "T100ProjectApp.h"

#include "T100Project.h"
#include "T100ProjectView.h"

namespace T100PROJECT{

T100ProjectApp::T100ProjectApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100WxWidgets::T100WxApp((T100WxWidgets::T100WxAppManager*)obj, quit)
{
    //ctor
    create();
}

T100ProjectApp::~T100ProjectApp()
{
    //dtor
    destroy();
}

T100VOID T100ProjectApp::create()
{
    T100BOOL        result;

    m_project   = T100NEW T100Project(this);
    result      = m_project->create();
    if(!result){
        T100SAFE_DELETE(m_project);
    }
}

T100VOID T100ProjectApp::destroy()
{
    T100SAFE_DELETE(m_project);
}

T100VOID T100ProjectApp::show()
{
    if(m_project){
        m_project->show();
        m_project->NewFile();
    }
}

}
