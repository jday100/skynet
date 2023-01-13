#ifndef T100MDITEXTFRAME_H
#define T100MDITEXTFRAME_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100Editor.h"

namespace T100IDE{
class T100IDEView;

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

        T100VOID        setView(T100IDEView*);
        T100VOID        setEditor(T100Editor::T100Editor*);

    protected:
        void OnSetFocus(wxFocusEvent& event);

    private:
        T100IDEView*                    m_view              = T100NULL;
        T100Editor::T100Editor*         m_editor            = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100MDITEXTFRAME_H
