#include "T100PaintCtrl.h"

#include <wx/sizer.h>

T100PaintCtrl::T100PaintCtrl(wxWindow *parent, wxWindowID id,
              const wxPoint& pos,
              const wxSize& size, long style,
              const wxValidator& validator,
              const wxString& name)
    :wxControl(parent, id, pos, size, style, validator, name)
{
    //ctor
    create();
}

T100PaintCtrl::~T100PaintCtrl()
{
    //dtor
    destroy();
}

void T100PaintCtrl::create()
{
    wxBoxSizer* BoxSizer1;

    BoxSizer1   = new wxBoxSizer(wxHORIZONTAL);
    m_canvas    = new T100PaintCanvas(this);

    BoxSizer1->Add(m_canvas, 1, wxALL | wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
}

void T100PaintCtrl::destroy()
{

}
