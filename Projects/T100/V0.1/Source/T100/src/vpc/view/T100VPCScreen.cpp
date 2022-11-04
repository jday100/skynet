#include "../../../include/vpc/view/T100VPCScreen.h"

//(*InternalHeaders(T100VPCScreen)
#include <wx/intl.h>
#include <wx/string.h>
//*)

namespace T100VPC{

//(*IdInit(T100VPCScreen)
//*)

BEGIN_EVENT_TABLE(T100VPCScreen,wxFrame)
	//(*EventTable(T100VPCScreen)
	//*)
END_EVENT_TABLE()

T100VPCScreen::T100VPCScreen(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCScreen::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCScreen)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VPCScreen::~T100VPCScreen()
{
	//(*Destroy(T100VPCScreen)
	//*)
}

}
