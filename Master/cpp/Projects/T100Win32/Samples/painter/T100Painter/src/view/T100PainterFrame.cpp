#include "T100PainterFrame.h"

#include <commctrl.h>
#include "T100PainterInvoking.h"
#include "gui/T100ListView.h"

T100PainterFrame::T100PainterFrame() :
    T100Frame(),
    m_listView()
{
    //ctor
}

T100PainterFrame::T100PainterFrame(T100Win32Application* app) :
    T100Frame(app, T100NULL),
    m_listView(app, this)
{
    //ctor
}

T100PainterFrame::~T100PainterFrame()
{
    //dtor
}

T100VOID T100PainterFrame::Create(T100Win32Application* app, T100WSTRING label)
{
    //T100Frame::Create((T100ApplicationEventHandler*)app, label);
    T100Frame::Create(app, label);

    init();
}

T100VOID T100PainterFrame::init()
{
    //InitListView();

    Maximize();

    ConnectMenu(T100MENU_ID_NEW, (T100EVENT_FUNCTION)&OnMenuNew);
    ConnectMenu(T100MENU_ID_QUIT, (T100EVENT_FUNCTION)&OnMenuQuit);

    Connect(T100EVENT_WINDOW_SIZE, (T100EVENT_FUNCTION)&OnFrameResize);
}

T100VOID T100PainterFrame::uninit()
{

}

T100VOID T100PainterFrame::InitListView()
{
    InitCommonControls();
    m_listView.Create((T100Win32Application*)GetApplicationPtr(), this);
    m_listView.Show();
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
