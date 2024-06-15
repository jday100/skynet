#include "T100WxRender.h"

#include <wx/dcbuffer.h>

BEGIN_EVENT_TABLE(T100WxRender,wxWindow)
    EVT_PAINT(T100WxRender::OnPaint)
END_EVENT_TABLE()

T100WxRender::T100WxRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxString& name)
    :wxWindow(parent, id, pos, size, style, name)
{
    //ctor
    TurnOn();
}

T100WxRender::~T100WxRender()
{
    //dtor
    TurnOff();
}

T100VOID T100WxRender::TurnOn()
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

T100VOID T100WxRender::TurnOff()
{

}

T100VOID T100WxRender::Draw()
{

}

T100VOID T100WxRender::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC       dc(this);

    dc.DrawCircle(100, 100, 10);
}
