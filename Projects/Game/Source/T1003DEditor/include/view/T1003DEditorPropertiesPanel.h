#ifndef T1003DEDITORPROPERTIESPANEL_H
#define T1003DEDITORPROPERTIESPANEL_H

#include <wx/propgrid/propgrid.h>
#include "T100Common.h"

class T1003DEditorPropertiesPanel : public wxPropertyGrid
{
    public:
        T1003DEditorPropertiesPanel(wxWindow *parent, wxWindowID id = wxID_ANY,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxPG_DEFAULT_STYLE,
                    const wxString& name = wxPropertyGridNameStr);
        virtual ~T1003DEditorPropertiesPanel();

        T100VOID                    update(T100UINT);

    protected:
        T100VOID                    load_dot();
        T100VOID                    load_line();
        T100VOID                    load_triangle();

    private:
        DECLARE_EVENT_TABLE()
};

#endif // T1003DEDITORPROPERTIESPANEL_H
