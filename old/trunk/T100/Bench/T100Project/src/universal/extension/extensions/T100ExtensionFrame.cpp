#include "T100ExtensionFrame.h"

T100ExtensionFrame::T100ExtensionFrame() :
    T100Extension()
{
    //ctor
}

T100ExtensionFrame::~T100ExtensionFrame()
{
    //dtor
}

T100VOID T100ExtensionFrame::SetFrame(wxFrame* frame)
{
    m_frame         = frame;
}

wxFrame* T100ExtensionFrame::GetFrame()
{
    return m_frame;
}
