#include "T100VPC.h"


T100VPC::T100VPC() :
    m_host()
{
    //ctor
}

T100VPC::~T100VPC()
{
    //dtor
}

T100VOID T100VPC::Create(T100Win32Application* application)
{
    m_frame     = T100NEW T100VPCFrame();

    m_frame->Create(application);

    m_frame->Show();
}

T100VOID T100VPC::Destroy()
{

}

T100VOID T100VPC::Start()
{
    m_host.SetFrame(m_frame);
    m_host.Start();
}

T100VOID T100VPC::Stop()
{
    m_host.Stop();
}
