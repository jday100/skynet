#ifndef T100PAINTERCANVAS_H
#define T100PAINTERCANVAS_H

#include <mutex>
#include <wx/scrolwin.h>
#include <wx/textctrl.h>
#include "T100PainterCommon.h"
#include "T100CanvasTransverter.h"

namespace T100Painter{

class T100PainterCanvas : public wxScrolledWindow
{
    friend class T100CanvasStateCommon;
    friend class T100CanvasStatePaint;
    friend class T100CanvasStateSelected;
    friend class T100CanvasStateSizing;
    public:
        T100PainterCanvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100PainterCanvas();

        T100BOOL            Load(T100PAINTER_ELEMENT_VECTOR*);
        T100VOID            Clear();


        T100BOOL            Remove(T100ElementBase*);

        T100VOID            Select(T100ElementBase*);
        T100VOID            Deselect();
        T100ElementBase*    GetCurrent();

        T100BOOL            Hit(T100INT, T100INT);

        T100VOID            Edit();

        T100BOOL            MouseMove(T100INT, T100INT);

        T100BOOL            GetVirtualPosition(T100INT, T100INT, T100INT&, T100INT&);

        T100CANVAS_STATE    GetState();
        T100BOOL            Change(T100CANVAS_STATE);

        T100BOOL            Resize(T100WORD, T100WORD);

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

        void OnKeyUp(wxKeyEvent& event);

        void OnResize(wxSizeEvent& event);

        void OnScrollBottom(wxScrollWinEvent& event);
        void OnScrollLineDown(wxScrollWinEvent& event);
        void OnScrollPageDown(wxScrollWinEvent& event);
        void OnScrollThumbTrack(wxScrollWinEvent& event);

    private:
        T100VOID            create();
        T100VOID            destroy();

        std::mutex          m_mutex;

        T100Component::T100CanvasTransverter                    m_manager;
        wxTextCtrl*         m_title         = T100NULL;

        T100ElementBase*                    m_current           = T100NULL;
        T100PAINTER_ELEMENT_VECTOR*         m_elements          = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERCANVAS_H
