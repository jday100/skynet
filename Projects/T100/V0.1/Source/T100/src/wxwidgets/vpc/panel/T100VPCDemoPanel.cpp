#include "../../../../include/wxwidgets/vpc/panel/T100VPCDemoPanel.h"

//(*InternalHeaders(T100VPCDemoPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100VPCDemoPanel)
//*)

BEGIN_EVENT_TABLE(T100VPCDemoPanel,wxPanel)
	//(*EventTable(T100VPCDemoPanel)
	//*)
END_EVENT_TABLE()

T100VPCDemoPanel::T100VPCDemoPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100VPCDemoPanel::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100VPCDemoPanel)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));

	Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100VPCDemoPanel::OnPaint);
	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&T100VPCDemoPanel::OnEraseBackground);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T100VPCDemoPanel::OnKeyDown);
	Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&T100VPCDemoPanel::OnKeyUp);
	Connect(wxEVT_CHAR,(wxObjectEventFunction)&T100VPCDemoPanel::OnChar);
	Connect(wxEVT_SET_FOCUS,(wxObjectEventFunction)&T100VPCDemoPanel::OnSetFocus);
	Connect(wxEVT_KILL_FOCUS,(wxObjectEventFunction)&T100VPCDemoPanel::OnKillFocus);
	Connect(wxEVT_MOTION,(wxObjectEventFunction)&T100VPCDemoPanel::OnMouseMove);
	//*)
}

T100VPCDemoPanel::~T100VPCDemoPanel()
{
	//(*Destroy(T100VPCDemoPanel)
	//*)
}


void T100VPCDemoPanel::OnPaint(wxPaintEvent& event)
{
}

void T100VPCDemoPanel::OnEraseBackground(wxEraseEvent& event)
{
}

void T100VPCDemoPanel::OnKeyDown(wxKeyEvent& event)
{
}

void T100VPCDemoPanel::OnKeyUp(wxKeyEvent& event)
{
}

void T100VPCDemoPanel::OnChar(wxKeyEvent& event)
{
}

void T100VPCDemoPanel::OnSetFocus(wxFocusEvent& event)
{
}

void T100VPCDemoPanel::OnKillFocus(wxFocusEvent& event)
{
}

void T100VPCDemoPanel::OnMouseMove(wxMouseEvent& event)
{
}
