#include "T100VPCApplication.h"

T100VPCApplication::T100VPCApplication() :
    T100Win32Application()
{
    //ctor
}

T100VPCApplication::~T100VPCApplication()
{
    //dtor
}

T100VOID T100VPCApplication::Create()
{
    T100Win32Application::Create();

    m_frame->SetSize(800, 600);
    CreateMenu(m_frame);
}

T100VOID T100VPCApplication::Destroy()
{
    T100Win32Application::Destroy();
}

T100VOID T100VPCApplication::CreateMenu(T100Frame* frame)
{
    T100MenuBar*    menuBar     = T100NEW T100MenuBar();
    T100Menu*       vmMenu      = T100NEW T100Menu(menuBar, L"Vm");

    T100MenuItem*   startItem   = T100NEW T100MenuItem(vmMenu, 1, L"Start");
    T100MenuItem*   stopItem    = T100NEW T100MenuItem(vmMenu, 2, L"Stop");

    vmMenu->AppendSeparator();

    T100MenuItem*   quitItem    = T100NEW T100MenuItem(vmMenu, 3, L"Quit");

    frame->ConnectMenu(1, (T100EVENT_FUNCTION)&OnStart, this);
    frame->ConnectMenu(2, (T100EVENT_FUNCTION)&OnStop, this);
    frame->ConnectMenu(3, (T100EVENT_FUNCTION)&OnQuit, this);

    frame->SetMenuBar(menuBar);
}

T100VOID T100VPCApplication::OnStart(T100MenuEvent& event)
{
    m_vpc       = T100NEW T100VPC();
    m_vpc->Create(this);
    m_vpc->Start();
}

T100VOID T100VPCApplication::OnStop(T100MenuEvent& event)
{
    m_vpc->Stop();
    m_vpc->Destroy();
    T100SAFE_DELETE(m_vpc);
}

T100VOID T100VPCApplication::OnQuit(T100MenuEvent& event)
{
    PostQuitMessage(0);
}
