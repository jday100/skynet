#ifndef T100PROJECTMDIMAINFRAME_H
#define T100PROJECTMDIMAINFRAME_H

#include <wx/docmdi.h>

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

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMDIMAINFRAME_H
