#include "wx\paint\view\T100WxPaintCtrl.h"

T100WxPaintCtrl::T100WxPaintCtrl(wxWindow *parent, wxWindowID id,
              const wxPoint& pos,
              const wxSize& size, long style,
              const wxValidator& validator,
              const wxString& name)
    :wxControl(parent, id, pos, size, style, validator, name)
{
    //ctor
    create();
}

T100WxPaintCtrl::~T100WxPaintCtrl()
{
    //dtor
    destroy();
}

T100VOID T100WxPaintCtrl::create()
{
    m_canvas    = T100NEW T100WxPaintCanvas(this);
}

T100VOID T100WxPaintCtrl::destroy()
{
    T100DELETE  m_canvas;
}
