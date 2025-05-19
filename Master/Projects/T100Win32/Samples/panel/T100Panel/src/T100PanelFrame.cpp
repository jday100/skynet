#include "T100PanelFrame.h"

#include "gui/T100Panel.h"
#include "gui/T100FillLayout.h"

T100PanelFrame::T100PanelFrame(T100Win32Application* app) :
    T100Frame(app)
{
    //ctor
}

T100PanelFrame::~T100PanelFrame()
{
    //dtor
}

T100VOID T100PanelFrame::Create(T100WSTRING label)
{
    T100Frame::Create(label);

    init();
}

T100VOID T100PanelFrame::init()
{
    T100Panel*          panel   = T100NEW T100Panel(GetApplicationPtr(), this);

    T100PanelStyle      style;

    style.WindowStyle   = WS_CHILD | WS_BORDER | WS_CAPTION | WS_SYSMENU;

    panel->Create(L"Panel", &style);
    panel->Show();

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    //layout->SetOrientationType(T100HORIZONTAL);

    this->SetLayout(layout);

}

T100VOID T100PanelFrame::uninit()
{

}
