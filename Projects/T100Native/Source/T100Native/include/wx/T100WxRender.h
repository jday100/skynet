#ifndef T100WXRENDER_H
#define T100WXRENDER_H

#include <wx/bitmap.h>
#include <wx/window.h>
#include "T100Common.h"
#include "T100Render.h"

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

        T100Render*         GetRender();

        T100VOID            DrawText(wxString);

    protected:
        T100VOID            OnPaint(wxPaintEvent& event);
        T100VOID            OnSize(wxSizeEvent& event);
        T100VOID            OnKeyDown(wxKeyEvent& event);
        T100VOID            OnChar(wxKeyEvent& event);

    protected:
        wxBitmap*           m_bitmap            = T100NULL;
        T100Render*         m_render            = T100NULL;

    private:
        T100VOID            TurnOn();
        T100VOID            TurnOff();

        DECLARE_EVENT_TABLE()
};

#endif // T100WXRENDER_H
