#include "T100DiskApp.h"

T100DiskApp::T100DiskApp() :
    T100Win32Application(),
    m_skeletal()
{
    //ctor
}

T100DiskApp::~T100DiskApp()
{
    //dtor
}

T100VOID T100DiskApp::Create()
{
    T100Win32Application::Create();

    m_frame->ConnectMenu(1003, (T100EVENT_FUNCTION)&OnQuit, this);

    m_skeletal.Create(this);
}

T100VOID T100DiskApp::Destroy()
{
    m_skeletal.Destroy();
}

T100VOID T100DiskApp::OnQuit(T100MenuEvent& event)
{
    PostQuitMessage(0);
}
