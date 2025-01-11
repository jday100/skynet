#ifndef T1003DEDITORMAINPANEL_H
#define T1003DEDITORMAINPANEL_H

#include <wx/panel.h>
#include "T1003DEditor.h"

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

        T100VOID                    setEditor(T1003DEditor*);

    protected:
        T1003DEditor*               m_editor            = T100NULL;

    private:
        void                        OnPaint(wxPaintEvent& event);

        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORMAINPANEL_H
