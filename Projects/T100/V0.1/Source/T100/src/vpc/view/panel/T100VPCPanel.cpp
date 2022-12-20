#include "T100VPCPanel.h"

#include <wx/intl.h>
#include <wx/string.h>

#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include "T100VPCDisplay.h"


namespace T100VPC{

BEGIN_EVENT_TABLE(T100VPCPanel, wxPanel)

END_EVENT_TABLE()

T100VPCPanel::T100VPCPanel(T100VPCDisplay* display, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
    :m_diaplay(display)
{
    //ctor
    BuildContent(parent, id, pos, size);
}

T100VPCPanel::~T100VPCPanel()
{
    //dtor
}

void T100VPCPanel::BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{

	//Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));

	Create(parent, id, wxDefaultPosition, wxSize(800, 600), wxTAB_TRAVERSAL, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);


    Connect(wxEVT_PAINT,                (wxObjectEventFunction)&T100VPCPanel::OnPaint);
	Connect(wxEVT_ERASE_BACKGROUND,     (wxObjectEventFunction)&T100VPCPanel::OnEraseBackground);
	Connect(wxEVT_CHAR,                 (wxObjectEventFunction)&T100VPCPanel::OnChar);
	Connect(wxEVT_MOTION,               (wxObjectEventFunction)&T100VPCPanel::OnMouseMove);

}

T100BOOL T100VPCPanel::paint()
{
    //
    #define     SCREEN_WIDTH    800
    #define     SCREEN_HEIGHT   600

    static char         buffer[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
    wxMemoryDC          memory;
    wxBufferedPaintDC   dc(this);

    T100WORD*           screen          = T100NULL;

    screen = (T100WORD*)&buffer;

    if(!m_diaplay->getScreen(screen)){
        return T100FALSE;
    }

    memcpy(buffer, screen, sizeof(buffer));

    wxBitmap bitmap(buffer, SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    memory.SelectObject(bitmap);
    dc.Blit(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &memory, 0, 0);
    memory.SelectObject(wxNullBitmap);

    this->Refresh();

    return T100TRUE;
}

void T100VPCPanel::OnPaint(wxPaintEvent& event)
{
    paint();
}

void T100VPCPanel::OnEraseBackground(wxEraseEvent& event)
{
}

void T100VPCPanel::OnChar(wxKeyEvent& event)
{
}

void T100VPCPanel::OnMouseMove(wxMouseEvent& event)
{
}

}
