#include "../../../include/font/view/T100FontFrame.h"

//(*InternalHeaders(T100FontFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "T100ThisAppCommon.h"
#include "T100App.h"
#include "T100Main.h"


namespace T100FontBuilder{

//(*IdInit(T100FontFrame)
const long T100FontFrame::ID_CUSTOM_FONT_PANEL = wxNewId();
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
	SetClientSize(wxSize(406,550));
	Move(wxDefaultPosition);
	FontPanel = new T100FontPanel(this,ID_CUSTOM_FONT_PANEL,wxPoint(192,296),wxDefaultSize);

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
    wxThreadEvent   temp(wxEVT_THREAD, T100Frame::ID_THREAD_CLOSE);

    temp.SetInt(T100APP_FONT_BUILDER);
    wxQueueEvent(wxGetApp().getManager()->getFrame(), temp.Clone());
}

}


