#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include <wx/scrolwin.h>
#include "T100PainterCommon.h"


namespace T100Painter{

class T100PainterCanvas : public wxScrolledWindow
{
    public:
        T100PainterCanvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100PainterCanvas();

        T100BOOL            Load(T100PAINTER_ELEMENT_VECTOR*);

    protected:
        void OnPaint(wxPaintEvent& event);

        void OnMouseLeftDown(wxMouseEvent& event);
        void OnMouseLeftUp(wxMouseEvent& event);
        void OnMouseMoving(wxMoveEvent& event);

    private:
        T100VOID            create();
        T100VOID            destroy();

        T100PAINTER_ELEMENT_VECTOR*         m_elements          = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERCANVAS_H
