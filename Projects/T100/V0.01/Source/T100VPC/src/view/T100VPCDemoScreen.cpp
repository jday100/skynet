#include "T100VPCDemoScreen.h"

#include <wx/intl.h>
#include <wx/string.h>

#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

#include "T100Display.h"


BEGIN_EVENT_TABLE(T100VPCDemoScreen,wxPanel)

END_EVENT_TABLE()

T100VPCDemoScreen::T100VPCDemoScreen(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //ctor
    BuildContent(parent,id,pos,size);
}

T100VPCDemoScreen::~T100VPCDemoScreen()
{
    //dtor
}

void T100VPCDemoScreen::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));

	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&T100VPCDemoScreen::OnEraseBackground);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&T100VPCDemoScreen::OnPaint);

}

T100VOID T100VPCDemoScreen::setDisplay(T100Display* display)
{
    m_display = display;
}

T100Display* T100VPCDemoScreen::getDisplay()
{
    return m_display;
}

void T100VPCDemoScreen::OnEraseBackground(wxEraseEvent& event)
{

}

void T100VPCDemoScreen::OnPaint(wxPaintEvent& event)
{
    #define     SCREEN_WIDTH    800
    #define     SCREEN_HEIGHT   600

    static char         buffer[SCREEN_WIDTH * SCREEN_HEIGHT * 4];
    wxMemoryDC          memory;
    wxBufferedPaintDC   dc(this);

    //memcpy(buffer, screen, sizeof(buffer));

    m_display->getScreen((T100WORD*)buffer);

    wxBitmap bitmap(buffer, SCREEN_WIDTH, SCREEN_HEIGHT, 32);

    //bitmap.SaveFile("hello.bmp", wxBITMAP_TYPE_BMP);

    memory.SelectObject(bitmap);
    dc.Blit(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, &memory, 0, 0);
    memory.SelectObject(wxNullBitmap);

    this->Refresh();
}
