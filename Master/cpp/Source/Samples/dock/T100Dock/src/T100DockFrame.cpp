#include "T100DockFrame.h"

#include "gui/T100Panel.h"
#include "gui/style/T100DockPanelStyle.h"

T100DockFrame::T100DockFrame() :
    T100Frame(),
    m_dockManager()
{
    //ctor
}

T100DockFrame::~T100DockFrame()
{
    //dtor
}

T100VOID T100DockFrame::Create(T100Win32Application* app, T100FrameStyle* style)
{
    T100Frame::Create(app, style);

    m_dockManager.SetFramePtr(this);

    Init();

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnResize);

    m_dockManager.Update();
}

T100VOID T100DockFrame::Init()
{
    T100DockPanelStyle      style;

    T100Panel*      panel1  = T100NEW T100Panel(this);
    T100Panel*      panel2  = T100NEW T100Panel(this);
    T100Panel*      panel3  = T100NEW T100Panel(this);

    panel1->Create(this, &style);
    panel2->Create(this, &style);
    panel3->Create(this, &style);

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
