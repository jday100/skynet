#include "../../include/view/T100VPCScreen.h"

//(*InternalHeaders(T100VPCScreen)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>


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

	Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100VPCScreen::OnPaint);
	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&T100VPCScreen::OnEraseBackground);
	//*)
}

T100VPCScreen::~T100VPCScreen()
{
	//(*Destroy(T100VPCScreen)
	//*)
}


void T100VPCScreen::OnEraseBackground(wxEraseEvent& event)
{
}

void T100VPCScreen::OnPaint(wxPaintEvent& event)
{
    paint();
}

T100BOOL T100VPCScreen::paint()
{
    //
    #define     SCREEN_WIDTH    800
    #define     SCREEN_HEIGHT   600

    static char         buffer[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
    wxMemoryDC          memory;
    wxBufferedPaintDC   dc(this);

    //memcpy(buffer, screen, sizeof(buffer));

    wxBitmap bitmap(buffer, SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    memory.SelectObject(bitmap);
    dc.Blit(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &memory, 0, 0);
    memory.SelectObject(wxNullBitmap);

    this->Refresh();

    return T100FALSE;
}
