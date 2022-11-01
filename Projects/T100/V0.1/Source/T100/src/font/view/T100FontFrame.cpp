#include "../../../include/font/view/T100FontFrame.h"

//(*InternalHeaders(T100FontFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

namespace T100FontBuilder{

//(*IdInit(T100FontFrame)
//*)

BEGIN_EVENT_TABLE(T100FontFrame,wxFrame)
	//(*EventTable(T100FontFrame)
	//*)
END_EVENT_TABLE()

T100FontFrame::T100FontFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100FontFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100FontFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

T100FontFrame::~T100FontFrame()
{
	//(*Destroy(T100FontFrame)
	//*)
}

}
