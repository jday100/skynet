#ifndef T100CANVAS_H
#define T100CANVAS_H

#include <mutex>
#include <wx/scrolwin.h>
#include "T100Common.h"
#include "T100DiagramInfo.h"
#include "T100CanvasTransverter.h"

class T100Canvas : public wxScrolledWindow
{
    public:
        T100Canvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100Canvas();

        T100VOID                SetDiagramInfo(T100DiagramInfo*);
        T100DiagramInfo*        GetDiagramInfo();

        T100VOID                Change(T100WORD);
        T100VOID                Paint();

        T100VOID                Select(T100ElementBase*);
        T100VOID                Deselect();
        T100VOID                Remove(T100ElementBase*);
        T100ElementBase*        Current();

        T100BOOL                GetVirtualPosition(T100INT, T100INT, T100INT&, T100INT&);

    public:
        static const long ID_THREAD_LOAD;

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
        //
        void OnThreadLoad(wxThreadEvent& event);

    private:
        T100VOID                                create();
        T100VOID                                destroy();

        std::mutex                              m_mutex;

        T100DiagramInfo*                        m_diagram               = T100NULL;
        T100CanvasTransverter                   m_transverter;

        T100ElementBase*                        m_current               = T100NULL;

        DECLARE_EVENT_TABLE()
};

#endif // T100CANVAS_H
