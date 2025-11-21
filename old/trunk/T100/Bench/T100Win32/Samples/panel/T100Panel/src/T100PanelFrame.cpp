#include "T100PanelFrame.h"

#include "gui/T100Panel.h"
#include "gui/T100FillLayout.h"

T100PanelFrame::T100PanelFrame() :
    T100Frame()
{
    //ctor
}

T100PanelFrame::~T100PanelFrame()
{
    //dtor
}

T100VOID T100PanelFrame::Create(T100Win32Application* app)
{
    T100Frame::Create(app);

    init();
}

T100VOID T100PanelFrame::init()
{
    T100Panel*          panel   = T100NEW T100Panel();

    T100PanelStyle      style;

    style.WindowStyle   = WS_CHILD | WS_BORDER | WS_CAPTION | WS_SYSMENU;

    panel->Create(this, &style);
    panel->Show();

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    //layout->SetOrientationType(T100HORIZONTAL);

    this->SetLayout(layout);

}

T100VOID T100PanelFrame::uninit()
{

}
