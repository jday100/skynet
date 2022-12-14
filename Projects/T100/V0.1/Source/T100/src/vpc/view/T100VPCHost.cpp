#include "T100VPCHost.h"

#include <wx/intl.h>
#include <wx/string.h>

namespace T100VPC{

BEGIN_EVENT_TABLE(T100VPCHost, wxFrame)

END_EVENT_TABLE()

T100VPCHost::T100VPCHost(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCHost::~T100VPCHost()
{
    //dtor
}

void T100VPCHost::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
}

}
