#ifndef T100WPAINTERCANVAS_H
#define T100WPAINTERCANVAS_H

#include <wx/scrolwin.h>
#include "T100Common.h"
#include "T100WPainterCanvasTransverter.h"

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

        T100VOID            Change(T100WORD);

    protected:
        void OnEraseBackGround(wxEraseEvent& event);
        void OnPaint(wxPaintEvent& event);

        void OnMouseEnter(wxMouseEvent& event);
        void OnMouseLeave(wxMouseEvent& event);
        void OnMouseLeftDown(wxMouseEvent& event);
        void OnMouseLeftUp(wxMouseEvent& event);
        void OnMouseLeftDClick(wxMouseEvent& event);
        void OnMouseMove(wxMouseEvent& event);

        void OnKeyUp(wxKeyEvent& event);

        void OnResize(wxSizeEvent& event);

        void OnScrollBottom(wxScrollWinEvent& event);
        void OnScrollLineDown(wxScrollWinEvent& event);
        void OnScrollPageDown(wxScrollWinEvent& event);
        void OnScrollThumbTrack(wxScrollWinEvent& event);

    private:
        T100VOID                                create();
        T100VOID                                destroy();

        T100WPainterCanvasTransverter           m_transverter;

        DECLARE_EVENT_TABLE()
};

#endif // T100WPAINTERCANVAS_H
