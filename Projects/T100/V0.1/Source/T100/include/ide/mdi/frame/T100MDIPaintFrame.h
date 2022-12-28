#ifndef T100MDIPAINTFRAME_H
#define T100MDIPAINTFRAME_H

#include <wx/docmdi.h>
#include "T100Common.h"

namespace T100IDE{

class T100MDIPaintFrame : public wxDocMDIChildFrame
{
    public:
        T100MDIPaintFrame(wxDocument *doc,
                       wxView *view,
                       wxMDIParentFrame *parent,
                       wxWindowID id = wxID_ANY,
                       const wxString& title = wxEmptyString,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDEFAULT_FRAME_STYLE,
                       const wxString& name = wxFrameNameStr);
        virtual ~T100MDIPaintFrame();

    protected:

    private:
        DECLARE_EVENT_TABLE()
};

}

#endif // T100MDIPAINTFRAME_H
