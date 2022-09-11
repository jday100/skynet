#include "T100VPCDisplay.h"

#include "T100VPCHostFrame.h"
#include "T100VPCDemoScreen.h"


T100VPCDisplay::T100VPCDisplay(T100QU32* host, wxFrame* parent)
    :T100Display(host),
    m_parent(parent)
{
    //ctor
}

T100VPCDisplay::~T100VPCDisplay()
{
    //dtor
}

T100BOOL T100VPCDisplay::create()
{
    return OnCreate();
}

T100BOOL T100VPCDisplay::OnCreate(void* d)
{
    T100VPCDemoScreen*      screen;
    T100VPCHostFrame*       frame;

    screen  = T100NEW T100VPCDemoScreen(m_parent, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
    frame   = static_cast<T100VPCHostFrame*>(m_parent);

    frame->BoxSizer1->Add(screen, 1, wxALL|wxEXPAND, 5);

    //frame->BoxSizer1->Fit(frame);
    //frame->BoxSizer1->SetSizeHints(frame);

    screen->setDisplay(this);

    return T100TRUE;
}
