#include "T100DockFrame.h"

#include "gui/T100Panel.h"

T100DockFrame::T100DockFrame(T100Win32Application* app) :
    T100Frame(app),
    m_dockManager()
{
    //ctor
}

T100DockFrame::~T100DockFrame()
{
    //dtor
}

T100VOID T100DockFrame::Create(T100WSTRING label, T100FrameStyle* style)
{
    T100Frame::Create(label, style);

    m_dockManager.SetFramePtr(this);

    Init();

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnResize);

    m_dockManager.Update();
}

T100VOID T100DockFrame::Init()
{
    T100DockPanelStyle      style;

    T100Panel*      panel1  = T100NEW T100Panel(GetApplicationPtr(), this);
    T100Panel*      panel2  = T100NEW T100Panel(GetApplicationPtr(), this);
    T100Panel*      panel3  = T100NEW T100Panel(GetApplicationPtr(), this);

    panel1->Create(L" Panel1", &style);
    panel2->Create(L" Panel2", &style);
    panel3->Create(L" Panel3", &style);

    panel1->Show();
    panel2->Show();
    panel3->Show();

    m_dockManager.AddPane(L"panel1", panel1, T100DockInfo().Left().BestSize(300, -1));
    m_dockManager.AddPane(L"panel2", panel2, T100DockInfo().Left().BestSize(300, -1));
    m_dockManager.AddPane(L"panel3", panel3, T100DockInfo().Center());
}

T100VOID T100DockFrame::OnResize(T100WindowEvent& event)
{
    m_dockManager.Update();
}
