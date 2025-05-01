#include "T100PainterView.h"

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

T100VOID T100PainterView::Create()
{
    m_frame.Create(L"T100Painter", 800, 600);
    m_mainMenu.Create(&m_frame);

    m_dockManager.SetFramePtr(&m_frame);

    m_entityPanel.Create(&m_frame, L"", 800, 600);
    m_canvas.Create(&m_frame, L"", 800, 600);

    m_dockManager.AddPane(L"entity", &m_entityPanel, T100DockInfo().Left().MinSize(300, -1).BestSize(300, -1));
    m_dockManager.AddPane(L"canvas", &m_canvas, T100DockInfo().Center());

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
