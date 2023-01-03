#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include <wx/scrolwin.h>
#include <wx/textctrl.h>
#include "T100PainterCommon.h"
#include "T100CanvasTransverter.h"

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

        T100VOID            Select(T100ElementBase*);
        T100VOID            Deselect();
        T100ElementBase*    GetCurrent();

        T100BOOL            Hit(T100INT, T100INT);

        T100VOID            Edit();

        T100BOOL            MouseMove(T100INT, T100INT);

        T100BOOL            GetVirtualPosition(T100INT, T100INT, T100INT&, T100INT&);

    public:
        static const long ID_TITLE;

        void OnTitleUpdated(wxCommandEvent& event);
        void OnLostFocus(wxFocusEvent& event);
        void OnLeave(wxCommandEvent& event);

    protected:
        void OnEraseBackGround(wxEraseEvent& event);
        void OnPaint(wxPaintEvent& event);

        void OnMouseLeftDown(wxMouseEvent& event);
        void OnMouseLeftUp(wxMouseEvent& event);
        void OnMouseMove(wxMouseEvent& event);
        void OnMouseLeftDClick(wxMouseEvent& event);

        void OnResize(wxSizeEvent& event);

    private:
        T100VOID            create();
        T100VOID            destroy();

        T100Component::T100CanvasTransverter                    m_manager;
        wxTextCtrl*         m_title         = T100NULL;

        T100ElementBase*                    m_current           = T100NULL;
        T100PAINTER_ELEMENT_VECTOR*         m_elements          = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERCANVAS_H
