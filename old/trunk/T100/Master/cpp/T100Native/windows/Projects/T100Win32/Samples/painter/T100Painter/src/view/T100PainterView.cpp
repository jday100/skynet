#include "T100PainterView.h"

#include "gui/T100Win32Application.h"
#include "gui/T100DockPanelStyle.h"

T100PainterView::T100PainterView() :
    m_dockManager(),
    m_frame(),
    m_mainMenu(),
    m_entityPanel(),
    m_canvas()
{
    //ctor
}

T100PainterView::~T100PainterView()
{
    //dtor
}

T100VOID T100PainterView::Create(T100Win32Application* app)
{
    T100DockPanelStyle      dockStyle;
    T100CanvasStyle         canvasStyle(dockStyle);
    T100PanelStyle          panelStyle(dockStyle);

    m_frame.Create(app);
    m_mainMenu.Create(&m_frame);

    app->SetFrame(&m_frame);
    m_dockManager.SetFrame(&m_frame);

    m_entityPanel.Create(&m_frame, L"", &panelStyle);
    m_canvas.Create(&m_frame, L"", &canvasStyle);

    m_dockManager.AddPane(L"entity", &m_entityPanel, T100DockInfo().Left().MinSize(300, -1).BestSize(300, -1));
    m_dockManager.AddPane(L"canvas", &m_canvas, T100DockInfo().Center());

    m_entityPanel.Show();
    m_canvas.Show();

    m_dockManager.Update();


}

T100VOID T100PainterView::Destroy()
{
    m_mainMenu.Destroy();
}

T100PainterFrame& T100PainterView::GetFrame()
{
    return m_frame;
}

T100DockManager& T100PainterView::GetDockManager()
{
    return m_dockManager;
}
