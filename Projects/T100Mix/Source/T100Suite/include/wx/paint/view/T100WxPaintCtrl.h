#ifndef T100WXPAINTCTRL_H
#define T100WXPAINTCTRL_H

#include <wx/control.h>
#include "T100Common.h"
#include "wx\paint\view\T100WxPaintCanvas.h"

class T100WxPaintCtrl : public wxControl
{
    public:
        T100WxPaintCtrl(wxWindow *parent, wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize, long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxControlNameStr);
        virtual ~T100WxPaintCtrl();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

    private:
        T100WxPaintCanvas*          m_canvas            = T100NULL;
};

#endif // T100WXPAINTCTRL_H
