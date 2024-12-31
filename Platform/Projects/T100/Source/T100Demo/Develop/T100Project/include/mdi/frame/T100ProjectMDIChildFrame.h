#ifndef T100PROJECTMDICHILDFRAME_H
#define T100PROJECTMDICHILDFRAME_H

#include <wx/mdi.h>

class T100ProjectMDIChildFrame : public wxMDIChildFrame
{
    public:
        T100ProjectMDIChildFrame(wxMDIParentFrame *parent,
                    wxWindowID id,
                    const wxString& title,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxDEFAULT_FRAME_STYLE,
                    const wxString& name = wxFrameNameStr);
        virtual ~T100ProjectMDIChildFrame();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T100PROJECTMDICHILDFRAME_H
