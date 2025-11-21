#ifndef T100CANVAS_H
#define T100CANVAS_H

#include <wx/textctrl.h>
#include <wx/scrolwin.h>
#include "T100DiagramCommon.h"
#include "T100DiagramInfo.h"
#include "T100ElementBase.h"
#include "T100CanvasTransverter.h"

class T100Canvas : public wxScrolledWindow
{
    friend class T100CanvasStateShow;
    friend class T100CanvasStateEdit;
    friend class T100CanvasStateCreate;
    friend class T100CanvasStateMoving;
    friend class T100CanvasStateSelected;
    friend class T100CanvasStateTieStart;
    friend class T100CanvasStateTieEnd;
    public:
        T100Canvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100Canvas();

        T100ElementBase*                m_current       = T100NULL;

        T100BOOL                        Change(T100CANVAS_STATE);

        T100BOOL                        Open(T100DiagramInfo*);

        T100BOOL                        Append();

        T100BOOL                        Save();

        T100BOOL                        Remove();

        T100BOOL                        Edit(T100ElementBase*);
        T100BOOL                        EditFinished();
        T100BOOL                        Select(T100ElementBase*);

        T100BOOL                        TieStart(T100ElementBase*);
        T100BOOL                        TieEnd(T100ElementBase*);

        T100BOOL                        Scale(T100INT);

        T100BOOL                        Clear();

        T100BOOL                        UpdateDiagram();

    protected:
        T100VOID OnEnter(wxMouseEvent&);
        T100VOID OnLeave(wxMouseEvent&);

        T100VOID OnEraseBackGround(wxEraseEvent& event);
        T100VOID OnPaint(wxPaintEvent& event);

        T100VOID OnMouseLeftDown(wxMouseEvent& event);
        T100VOID OnMouseLeftUp(wxMouseEvent& event);
        T100VOID OnMouseLeftDClick(wxMouseEvent& event);
        T100VOID OnMouseMove(wxMouseEvent& event);
        T100VOID OnMouseWheel(wxMouseEvent& event);

        T100VOID OnKeyDown(wxKeyEvent& event);
        T100VOID OnKeyUp(wxKeyEvent& event);

        T100VOID OnResize(wxSizeEvent& event);

        T100VOID OnScrollBottom(wxScrollWinEvent& event);
        T100VOID OnScrollLineDown(wxScrollWinEvent& event);
        T100VOID OnScrollPageDown(wxScrollWinEvent& event);
        T100VOID OnScrollThumbTrack(wxScrollWinEvent& event);

    private:
        T100CanvasTransverter           m_manager;
        T100DiagramInfo*                m_diagram       = T100NULL;
        T100DIAGRAM_ELEMENT_VECTOR*     m_elements      = T100NULL;

        wxPoint                         m_position;
        wxTextCtrl*                     m_edit          = T100NULL;

        T100FLOAT                       m_scale         = 1;

        wxPoint                         GetVirtualPosition(wxPoint);

        T100VOID                        init();
        T100VOID                        uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T100CANVAS_H
