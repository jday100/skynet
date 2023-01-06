#ifndef T100MDIPAINTFRAME_H
#define T100MDIPAINTFRAME_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100Painter.h"

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

        T100VOID            setPainter(T100Painter::T100Painter*);

    protected:
        void OnSetFocus(wxFocusEvent& event);

    private:
        T100Painter::T100Painter*       m_painter           = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100MDIPAINTFRAME_H
