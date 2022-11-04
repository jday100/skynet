#include "../../../include/vpc/view/T100VPCFrame.h"

//(*InternalHeaders(T100VPCFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

namespace T100VPC{

//(*IdInit(T100VPCFrame)
//*)

BEGIN_EVENT_TABLE(T100VPCFrame,wxFrame)
	//(*EventTable(T100VPCFrame)
	//*)
END_EVENT_TABLE()

T100VPCFrame::T100VPCFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCFrame::~T100VPCFrame()
{
	//(*Destroy(T100VPCFrame)
	//*)
}

}

