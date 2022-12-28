#ifndef T100PAINTCTRL_H
#define T100PAINTCTRL_H

#include "T100PainterCanvas.h"

namespace T100WxWidgets{

class T100PaintCtrl : public T100Painter::T100PainterCanvas
{
    public:
        T100PaintCtrl(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100PaintCtrl();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTCTRL_H
