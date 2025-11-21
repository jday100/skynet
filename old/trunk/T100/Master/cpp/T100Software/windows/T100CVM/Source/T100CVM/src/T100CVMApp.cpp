#include "T100CVMApp.h"

T100CVMApp::T100CVMApp() :
    T100Win32Application(),
    m_skeletal(),
    m_server()
{
    //ctor
}

T100CVMApp::~T100CVMApp()
{
    //dtor
}

T100VOID T100CVMApp::Create()
{
    T100Win32Application::Create();

    m_frame->ConnectMenu(100, (T100EVENT_FUNCTION)&OnStart, this);
    m_frame->ConnectMenu(101, (T100EVENT_FUNCTION)&OnStop, this);

    m_skeletal.Create(this);

    m_server.SetPath(L"./");
    m_server.SetPrefix(L"T100VM");
    m_server.SetSuffix(L".dll");
    m_server.Start();
}

T100VOID T100CVMApp::Destroy()
{
    m_server.Stop();
    m_skeletal.Destroy();
}

T100VOID T100CVMApp::OnStart(T100MenuEvent& event)
{
    m_server.Load(L"HyperV");

    void(*method)() = (void(*)())m_server.GetMethod(L"HyperV", L"VM_Start");

    method();
}

T100VOID T100CVMApp::OnStop(T100MenuEvent& event)
{

}
