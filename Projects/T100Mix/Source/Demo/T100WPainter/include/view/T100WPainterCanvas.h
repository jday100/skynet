#ifndef T100WPAINTERCANVAS_H
#define T100WPAINTERCANVAS_H

#include <wx/scrolwin.h>


class T100WPainterCanvas : public wxScrolledWindow
{
    public:
        T100WPainterCanvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100WPainterCanvas();

    protected:
        void OnEraseBackGround(wxEraseEvent& event);
        void OnPaint(wxPaintEvent& event);

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100WPAINTERCANVAS_H
