#ifndef T100PROJECTMDIMAINFRAME_H
#define T100PROJECTMDIMAINFRAME_H

#include <wx/docmdi.h>
#include "T100ProjectView.h"

class T100ProjectMDIMainFrame : public wxDocMDIParentFrame
{
    public:
        T100ProjectMDIMainFrame(wxDocManager *manager,
                        wxFrame *parent,
                        wxWindowID id,
                        const wxString& title,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxDEFAULT_FRAME_STYLE,
                        const wxString& name = wxFrameNameStr);
        virtual ~T100ProjectMDIMainFrame();

        T100VOID                    setView(T100ProjectView*);

    protected:
        void OnResize(wxSizeEvent& event);
        void OnClose(wxCloseEvent& event);

    private:
        T100ProjectView*            m_view          = T100NULL;

        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMDIMAINFRAME_H
