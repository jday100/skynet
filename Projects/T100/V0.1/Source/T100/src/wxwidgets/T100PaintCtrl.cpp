#include "T100PaintCtrl.h"

namespace T100WxWidgets{

BEGIN_EVENT_TABLE(T100PaintCtrl,T100Painter::T100PainterCanvas)

END_EVENT_TABLE()

T100PaintCtrl::T100PaintCtrl(wxWindow *parent, wxWindowID winid, const wxPoint& pos,
                     const wxSize& size, long style, const wxString& name)
    :T100PainterCanvas(parent, winid, pos, size, style, name)
{
    //ctor
}

T100PaintCtrl::~T100PaintCtrl()
{
    //dtor
}

}
