#ifndef T100IDEMAINFRAME_H
#define T100IDEMAINFRAME_H

#include <wx/aui/aui.h>
#include <wx/docmdi.h>
#include "T100IDEView.h"

namespace T100IDE{

class T100IDEMainFrame : public wxDocMDIParentFrame
{
    public:
        T100IDEMainFrame(wxDocManager *manager,
                        wxFrame *parent,
                        wxWindowID id = wxID_ANY,
                        const wxString& title = wxEmptyString,
                        const wxPoint& pos = wxDefaultPosition,
                        const wxSize& size = wxDefaultSize,
                        long style = wxDEFAULT_FRAME_STYLE,
                        const wxString& name = wxFrameNameStr);
        virtual ~T100IDEMainFrame();

        T100VOID            setView(T100IDEView*);
        T100IDEView*        getView();

    protected:

    private:
        T100IDEView*        m_view          = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100IDEMAINFRAME_H
