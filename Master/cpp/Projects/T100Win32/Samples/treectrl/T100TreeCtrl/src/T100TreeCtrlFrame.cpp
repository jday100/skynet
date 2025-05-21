#include "T100TreeCtrlFrame.h"

#include "gui/T100FillLayout.h"

T100TreeCtrlFrame::T100TreeCtrlFrame(T100Win32Application* app) :
    T100Frame(app, T100NULL),
    m_treeCtrl()
{
    //ctor
}

T100TreeCtrlFrame::~T100TreeCtrlFrame()
{
    //dtor
}

T100VOID T100TreeCtrlFrame::Create(T100WSTRING label)
{
    T100Frame::Create(label);

    m_treeCtrl.Create(GetApplicationPtr(), this);

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    SetLayout(layout);

    init();
}

T100VOID T100TreeCtrlFrame::init()
{
    m_treeCtrl.Append(L"Dot");
    m_treeCtrl.Append(L"Line");

    Connect(T100EVENT_COMMAND, (T100EVENT_FUNCTION)&OnWindowMessage, this);
}

T100VOID T100TreeCtrlFrame::uninit()
{

}

T100VOID T100TreeCtrlFrame::OnWindowMessage(T100WindowEvent& event)
{

}
