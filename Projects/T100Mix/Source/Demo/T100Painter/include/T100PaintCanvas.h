#ifndef T100PAINTCANVAS_H
#define T100PAINTCANVAS_H

#include <wx/scrolwin.h>

class T100PaintCanvas : public wxScrolledWindow
{
    public:
        T100PaintCanvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100PaintCanvas();

    protected:
        void OnPaint(wxPaintEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
        void OnMouseWheel(wxMouseEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftDClick(wxMouseEvent& event);
        void OnResize(wxSizeEvent& event);

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100PAINTCANVAS_H
