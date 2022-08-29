#include "T100VPCView.h"

#include "T100VPCScreen.h"


T100VPCView::T100VPCView()
{
    //ctor
}

T100VPCView::~T100VPCView()
{
    //dtor
}

T100VOID T100VPCView::setFrame(wxFrame* frame)
{
    m_frame = frame;
}

wxFrame* T100VPCView::getFrame()
{
    return m_frame;
}

T100BOOL T100VPCView::show()
{
    m_screen = T100NEW T100VPCScreen(T100NULL);

    m_screen->Show();
}

T100BOOL T100VPCView::hide()
{
    if(m_screen){
        m_screen->Hide();

        m_screen->Close();
    }
}
