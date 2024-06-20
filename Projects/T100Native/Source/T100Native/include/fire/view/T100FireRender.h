#ifndef T100FIRERENDER_H
#define T100FIRERENDER_H

#include "T100WxRender.h"

class T100FireRender : public T100WxRender
{
    public:
        T100FireRender(wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPanelNameStr);
        virtual ~T100FireRender();

    protected:
        T100VOID            OnKeyDown(wxKeyEvent& event);
        T100VOID            OnChar(wxKeyEvent& event);

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100FIRERENDER_H
