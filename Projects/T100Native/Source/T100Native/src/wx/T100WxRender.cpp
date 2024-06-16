#include "T100WxRender.h"

#include <wx/dcbuffer.h>

BEGIN_EVENT_TABLE(T100WxRender,wxWindow)
    EVT_PAINT(T100WxRender::OnPaint)
    EVT_SIZE(T100WxRender::OnSize)
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

    m_bitmap    = T100NEW wxBitmap();
    m_render    = T100NEW T100Render();

    m_bitmap->SetWidth(100);
    m_bitmap->SetHeight(100);

}

T100VOID T100WxRender::TurnOff()
{
    T100SAFE_DELETE(m_render)
}

T100VOID T100WxRender::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC       dc(this);

    dc.DrawCircle(100, 100, 10);

    m_render->Draw();

    m_bitmap    = T100NEW wxBitmap((const char*)m_render->GetData(), m_render->GetWidth(), m_render->GetHeight(), 32);

    //test
    m_bitmap->SaveFile(_T("screen.bmp"), wxBITMAP_TYPE_BMP);

    dc.SelectObject(*m_bitmap);
}

T100VOID T100WxRender::OnSize(wxSizeEvent& event)
{
    T100INT             width, height;

    width   = event.GetSize().GetWidth();
    height  = event.GetSize().GetHeight();

    m_bitmap->SetSize(width, height);
    m_render->SetSize(width, height);

    m_bitmap    = T100NEW wxBitmap((const char*)m_render->GetData(), width, height);
}
