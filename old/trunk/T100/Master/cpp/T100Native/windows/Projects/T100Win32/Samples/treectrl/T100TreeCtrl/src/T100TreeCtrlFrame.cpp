#include "T100TreeCtrlFrame.h"

#include "gui/T100FillLayout.h"
#include "gui/common/T100EventCommon.h"


T100TreeCtrlFrame::T100TreeCtrlFrame() :
    T100Frame(),
    m_treeCtrl()
{
    //ctor
}

T100TreeCtrlFrame::T100TreeCtrlFrame(T100Win32Application* app) :
    T100Frame(app),
    m_treeCtrl()
{
    //ctor
}

T100TreeCtrlFrame::~T100TreeCtrlFrame()
{
    //dtor
}

T100VOID T100TreeCtrlFrame::Create(T100Win32Application* application)
{
    T100Frame::Create(application);

    m_treeCtrl.Create(this);
    m_treeCtrl.Show();

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
