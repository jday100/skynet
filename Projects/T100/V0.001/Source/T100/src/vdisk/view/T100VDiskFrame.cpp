#include "../../../include/vdisk/view/T100VDiskFrame.h"

//(*InternalHeaders(T100VDiskFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VDiskFrame)
//*)

BEGIN_EVENT_TABLE(T100VDiskFrame,wxFrame)
	//(*EventTable(T100VDiskFrame)
	//*)
END_EVENT_TABLE()

T100VDiskFrame::T100VDiskFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VDiskFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VDiskFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100VDiskFrame::~T100VDiskFrame()
{
	//(*Destroy(T100VDiskFrame)
	//*)
}

