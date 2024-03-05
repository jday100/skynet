#ifndef T100MDIPROJECTFRAME_H
#define T100MDIPROJECTFRAME_H

#include <wx/docmdi.h>
#include "T100Common.h"
#include "T100Project.h"

namespace T100IDE{
class T100IDEView;

class T100MDIProjectFrame : public wxDocMDIChildFrame
{
    public:
        T100MDIProjectFrame(wxDocument *doc,
                       wxView *view,
                       wxMDIParentFrame *parent,
                       wxWindowID id = wxID_ANY,
                       const wxString& title = wxEmptyString,
                       const wxPoint& pos = wxDefaultPosition,
                       const wxSize& size = wxDefaultSize,
                       long style = wxDEFAULT_FRAME_STYLE,
                       const wxString& name = wxFrameNameStr);
        virtual ~T100MDIProjectFrame();

        T100VOID        setView(T100IDEView*);
        T100VOID        setProject(T100PROJECT::T100Project*);

    protected:
        void OnSetFocus(wxFocusEvent& event);

    private:
        T100IDEView*                    m_view              = T100NULL;
        T100PROJECT::T100Project*       m_project           = T100NULL;

        DECLARE_EVENT_TABLE()
};

}

#endif // T100MDIPROJECTFRAME_H
