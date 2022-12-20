#include "T100VPCApp.h"

#include "T100VPC.h"

namespace T100VPC{

T100VPCApp::T100VPCApp(T100ThisAppManager* obj, T100BOOL quit)
    :T100Library::T100AppBase(obj, quit)
{
    //ctor
    create();
}

T100VPCApp::~T100VPCApp()
{
    //dtor
    destroy();
}

T100VOID T100VPCApp::create()
{
    m_vpc = T100NEW T100VPC(this);
}

T100VOID T100VPCApp::destroy()
{
    T100SAFE_DELETE(m_vpc);
}

T100BOOL T100VPCApp::show()
{
    if(!m_vpc){
        return T100FALSE;
    }

    return m_vpc->show();
}

}
