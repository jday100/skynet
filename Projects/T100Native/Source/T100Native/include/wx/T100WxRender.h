#ifndef T100WXRENDER_H
#define T100WXRENDER_H

#include <wx/window.h>
#include "T100Common.h"

class T100WxRender : public wxWindow
{
    public:
        T100WxRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPanelNameStr);
        virtual ~T100WxRender();

        T100VOID            Draw();

    protected:
        T100VOID            OnPaint(wxPaintEvent& event);

    private:
        T100VOID            TurnOn();
        T100VOID            TurnOff();

        DECLARE_EVENT_TABLE()
};

#endif // T100WXRENDER_H
