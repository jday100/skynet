#include "wx\paint\view\T100WxPaintCtrl.h"

#include <wx/sizer.h>


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
    wxBoxSizer* BoxSizer1;

    BoxSizer1   = new wxBoxSizer(wxHORIZONTAL);
    m_canvas    = T100NEW T100WxPaintCanvas(this);

    BoxSizer1->Add(m_canvas, 1, wxALL | wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

}

T100VOID T100WxPaintCtrl::destroy()
{
    T100SAFE_DELETE(m_canvas)
}
