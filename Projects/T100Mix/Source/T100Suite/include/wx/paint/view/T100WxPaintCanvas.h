#ifndef T100WXPAINTCANVAS_H
#define T100WXPAINTCANVAS_H

#include <mutex>
#include <wx/scrolwin.h>
#include "T100Common.h"
#include "wx\paint\serve\canvas\T100WxPaintCanvasStateTransverter.h"

class T100WxPaintCanvas : public wxScrolledWindow
{
    public:
        T100WxPaintCanvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100WxPaintCanvas();

    protected:
        void OnPaint(wxPaintEvent& event);
        void OnEraseBackGround(wxEraseEvent& event);
        void OnMouseWheel(wxMouseEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnLeftDClick(wxMouseEvent& event);
        void OnResize(wxSizeEvent& event);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        std::mutex          m_mutex;

        float               m_scale     = 1.0;

        T100WxPaintCanvasStateTransverter               m_manager;

        DECLARE_EVENT_TABLE()
};

#endif // T100WXPAINTCANVAS_H
