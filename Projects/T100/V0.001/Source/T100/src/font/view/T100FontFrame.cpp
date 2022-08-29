#include "../../../include/font/view/T100FontFrame.h"

//(*InternalHeaders(T100FontFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100FontFrame)
const long T100FontFrame::ID_FONTPANEL = wxNewId();
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
	SetClientSize(wxSize(400,550));
	Move(wxDefaultPosition);
	FontPanel = new T100FontPanel(this,ID_FONTPANEL,wxPoint(144,344),wxDefaultSize);

	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&T100FontFrame::OnClose);
	//*)
}

T100FontFrame::~T100FontFrame()
{
	//(*Destroy(T100FontFrame)
	//*)
}


void T100FontFrame::OnClose(wxCloseEvent& event)
{
    exit(0);
}
