#ifndef T100DIAGRAMPROPERTYPANEL_H
#define T100DIAGRAMPROPERTYPANEL_H

#include <wx/propgrid/propgrid.h>
#include "T100Common.h"

class T100DiagramPropertyPanel : public wxPropertyGrid
{
    public:
        T100DiagramPropertyPanel(wxWindow *parent, wxWindowID id = wxID_ANY,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxPG_DEFAULT_STYLE,
                    const wxString& name = wxPropertyGridNameStr);
        virtual ~T100DiagramPropertyPanel();

    protected:

    private:
};

#endif // T100DIAGRAMPROPERTYPANEL_H
