#include "T100PainterFrame.h"

#include "T100PainterInvoking.h"
#include "gui/listctrl/T100ListCtrl.h"

T100PainterFrame::T100PainterFrame() :
    T100Frame(),
    m_listCtrl()
{
    //ctor
}

T100PainterFrame::~T100PainterFrame()
{
    //dtor
}

T100VOID T100PainterFrame::Create(T100WSTRING title, T100UINT width, T100UINT height)
{
    T100Frame::Create(title, width, height);
    init();
}

T100VOID T100PainterFrame::init()
{
    //InitListCtrl();

    Maximize();

    Connect(T100EVENT_MENU, T100MENU_ID_NEW, (T100EVENT_CALL)&OnMenuNew);
    Connect(T100EVENT_MENU, T100MENU_ID_QUIT, (T100EVENT_CALL)&OnMenuQuit);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_CALL)&OnFrameResize);
}

T100VOID T100PainterFrame::uninit()
{

}

T100VOID T100PainterFrame::InitListCtrl()
{
    InitCommonControls();
    m_listCtrl.Create(this);
    m_listCtrl.Show();
    //m_listCtrl.Append(L"ShowItem1");
}

T100VOID T100PainterFrame::OnMenuNew(T100CommandEvent& event)
{
    T100PainterInvoking::MenuNew();
}

T100VOID T100PainterFrame::OnMenuQuit(T100CommandEvent& event)
{
    T100PainterInvoking::MenuQuit();
}

T100VOID T100PainterFrame::OnFrameResize(T100WindowEvent& event)
{
    T100PainterInvoking::FrameResize();
}
