#include "T100VPCDisplay.h"

#include "T100VPCHost.h"
#include "T100VPCPanel.h"

namespace T100VPC{

T100VPCDisplay::T100VPCDisplay(T100QU32::T100QU32* host, T100VPCHost* frame, T100DisplayInfo* info)
    :T100Display(host), m_host(host), m_frame(frame), m_info(info)
{
    //ctor
}

T100VPCDisplay::~T100VPCDisplay()
{
    //dtor
}

T100BOOL T100VPCDisplay::create()
{
    m_panel     = T100NEW T100VPCPanel(this, m_frame);

    m_frame->SetClientSize(wxSize(m_info->m_width, m_info->m_height));
}

T100BOOL T100VPCDisplay::OnCreate(void* d)
{

}

T100BOOL T100VPCDisplay::load()
{

}

}
