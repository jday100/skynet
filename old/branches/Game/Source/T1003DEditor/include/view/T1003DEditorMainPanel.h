#ifndef T1003DEDITORMAINPANEL_H
#define T1003DEDITORMAINPANEL_H

#include <wx/bitmap.h>
#include <wx/dcclient.h>
#include <wx/panel.h>
#include "T100Common.h"

class T1003DEditorView;

class T1003DEditorMainPanel : public wxPanel
{
    public:
        T1003DEditorMainPanel(wxWindow *parent,
                wxWindowID winid = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorMainPanel();

        T100VOID                    setView(T1003DEditorView*);

    protected:
        T100BOOL                    m_drawLine          = T100FALSE;
        T1003DEditorView*           m_view              = T100NULL;

        T100VOID                    SaveWindow(wxDC&);

    private:
        T100UINT                    m_width;
        T100UINT                    m_height;
        wxBitmap*                   m_bitmap            = T100NULL;
        void                        OnPaint(wxPaintEvent& event);
        void                        OnResize(wxSizeEvent& event);
        void                        OnKeyDown(wxKeyEvent& event);
        void                        OnKeyUp(wxKeyEvent& event);
        void                        OnLeftDown(wxMouseEvent& event);
        void                        OnLeftUp(wxMouseEvent& event);
        void                        OnMouseWheel(wxMouseEvent& event);
        void                        OnMouseMove(wxMouseEvent& event);

        void                        OnIdle(wxIdleEvent& event);

        T100VOID                    init();
        T100VOID                    uninit();

        T100VOID                    Resize(T100UINT, T100UINT);
        T100VOID                    DrawLine(wxDC&);

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAINPANEL_H
