#include "T100ListViewFrame.h"

#include "gui/T100FillLayout.h"

T100ListViewFrame::T100ListViewFrame(T100Win32Application* app) :
    T100Frame(app, T100NULL),
    m_listView()
{
    //ctor
}

T100ListViewFrame::~T100ListViewFrame()
{
    //dtor
}

T100VOID T100ListViewFrame::Create(T100WSTRING label)
{
    T100Frame::Create(label);

    m_listView.Create(GetApplicationPtr(), this);

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    SetLayout(layout);

    init();
}

T100VOID T100ListViewFrame::init()
{
    m_listView.Append(L"Dot");
    m_listView.Append(L"Line");

    Connect(T100EVENT_COMMAND, (T100EVENT_FUNCTION)&OnWindowMessage, this);
}

T100VOID T100ListViewFrame::uninit()
{

}

T100VOID T100ListViewFrame::OnWindowMessage(T100WindowEvent& event)
{

}
