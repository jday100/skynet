#ifndef T100MDITEXTFRAME_H
#define T100MDITEXTFRAME_H

#include <wx/docmdi.h>
#include "T100Common.h"

namespace T100IDE{

class T100MDITextFrame : public wxDocMDIChildFrame
{
    public:
        T100MDITextFrame(wxDocument *doc,
                       wxView *view,
                       wxMDIParentFrame *parent,
                       wxWindowID id = wxID_ANY,
                       const wxString& title = wxEmptyString,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDEFAULT_FRAME_STYLE,
                       const wxString& name = wxFrameNameStr);
        virtual ~T100MDITextFrame();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

}

#endif // T100MDITEXTFRAME_H
