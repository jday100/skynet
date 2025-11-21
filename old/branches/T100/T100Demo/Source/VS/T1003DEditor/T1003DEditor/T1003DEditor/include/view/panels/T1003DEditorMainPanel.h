#ifndef T1003DEDITORMAINPANEL_H
#define T1003DEDITORMAINPANEL_H

#include <atomic>
#include <wx/panel.h>
#include "T100Common.h"

class T1003DEditorMainPanel : public wxPanel
{
    friend class T1003DEditorCallback;
    public:
        T1003DEditorMainPanel(wxWindow *parent,
            wxWindowID winid = wxID_ANY,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTAB_TRAVERSAL | wxNO_BORDER,
            const wxString& name = wxPanelNameStr);
        virtual ~T1003DEditorMainPanel();

        T100UINT                GetWidth();
        T100UINT                GetHeight();

        T100VOID                SetAppendState(T100BOOL = T100TRUE);

    protected:
        T100VOID                OnEnterWindow(wxMouseEvent& event);
        T100VOID                OnLeaveWindow(wxMouseEvent& event);
        T100VOID                OnKeyDown(wxKeyEvent& event);
        T100VOID                OnKeyUp(wxKeyEvent& event);
        T100VOID                OnMouseLeftDown(wxMouseEvent& event);
        T100VOID                OnMouseRightDown(wxMouseEvent& event);
        T100VOID                OnMouseMove(wxMouseEvent& event);

    private:
        std::atomic_bool        m_appendState;
        std::atomic_bool        m_ctrlKey;

        T100VOID                init();
        T100VOID                uninit();

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAINPANEL_H
