#include "../../../../include/wxwidgets/painter/frame/T100PainterDemoFrame.h"

//(*InternalHeaders(T100PainterDemoFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(T100PainterDemoFrame)
const long T100PainterDemoFrame::ID_SCROLLEDWINDOW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(T100PainterDemoFrame,wxFrame)
	//(*EventTable(T100PainterDemoFrame)
	//*)
END_EVENT_TABLE()

T100PainterDemoFrame::T100PainterDemoFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	BuildContent(parent,id,pos,size);
}

void T100PainterDemoFrame::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(T100PainterDemoFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxPoint(384,304), wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));

	Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100PainterDemoFrame::OnPaint);
	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&T100PainterDemoFrame::OnEraseBackground);
	Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&T100PainterDemoFrame::OnKeyDown);
	Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&T100PainterDemoFrame::OnKeyUp);
	Connect(wxEVT_CHAR,(wxObjectEventFunction)&T100PainterDemoFrame::OnChar);
	Connect(wxEVT_SIZE,(wxObjectEventFunction)&T100PainterDemoFrame::OnResize);
	//*)
}

T100PainterDemoFrame::~T100PainterDemoFrame()
{
	//(*Destroy(T100PainterDemoFrame)
	//*)
}


void T100PainterDemoFrame::OnPaint(wxPaintEvent& event)
{
}

void T100PainterDemoFrame::OnEraseBackground(wxEraseEvent& event)
{
}

void T100PainterDemoFrame::OnResize(wxSizeEvent& event)
{
}

void T100PainterDemoFrame::OnKeyDown(wxKeyEvent& event)
{
}

void T100PainterDemoFrame::OnKeyUp(wxKeyEvent& event)
{
}

void T100PainterDemoFrame::OnChar(wxKeyEvent& event)
{
}

void T100PainterDemoFrame::OnScrollBar1Scroll(wxScrollEvent& event)
{
}

void T100PainterDemoFrame::OnScrollBar1ScrollBottom(wxScrollEvent& event)
{
}

void T100PainterDemoFrame::OnScrollBar1ScrollLineDown(wxScrollEvent& event)
{
}

void T100PainterDemoFrame::OnScrollBar1ScrollPageDown(wxScrollEvent& event)
{
}

void T100PainterDemoFrame::OnScrollBar1ScrollChanged(wxScrollEvent& event)
{
}
