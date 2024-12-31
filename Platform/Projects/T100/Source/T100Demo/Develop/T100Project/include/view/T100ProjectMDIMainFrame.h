#ifndef T100PROJECTMDIMAINFRAME_H
#define T100PROJECTMDIMAINFRAME_H

#include <wx/mdi.h>

class T100ProjectMDIMainFrame : public wxMDIParentFrame
{
    public:
        T100ProjectMDIMainFrame(wxWindow *parent,
                     wxWindowID id,
                     const wxString& title,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxDEFAULT_FRAME_STYLE | wxVSCROLL | wxHSCROLL,
                     const wxString& name = wxFrameNameStr);
        virtual ~T100ProjectMDIMainFrame();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMDIMAINFRAME_H
