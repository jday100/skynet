#include "T100PanelFrame.h"

#include "gui/T100Panel.h"
#include "gui/layout/T100FillLayout.h"

T100PanelFrame::T100PanelFrame() :
    T100Frame()
{
    //ctor
}

T100PanelFrame::~T100PanelFrame()
{
    //dtor
}

T100VOID T100PanelFrame::Create(T100WSTRING label, T100UINT width, T100UINT height)
{
    T100Frame::Create(label, width, height);

    init();
}

T100VOID T100PanelFrame::init()
{
    T100Panel*          panel   = T100NEW T100Panel();

    panel->Create(this, L"", 800, 600);

    T100FillLayout*     layout  = T100NEW T100FillLayout();

    //layout->SetOrientationType(T100HORIZONTAL);

    this->SetLayoutPtr(layout);

}

T100VOID T100PanelFrame::uninit()
{

}
