#include "../../include/wx/T100VMFrame.h"

//(*InternalHeaders(T100VMFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VMFrame)
//*)

BEGIN_EVENT_TABLE(T100VMFrame,wxFrame)
	//(*EventTable(T100VMFrame)
	//*)
END_EVENT_TABLE()

T100VMFrame::T100VMFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VMFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VMFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	MenuBar1 = new wxMenuBar();
	SetMenuBar(MenuBar1);
	//*)
}

T100VMFrame::~T100VMFrame()
{
	//(*Destroy(T100VMFrame)
	//*)
}

