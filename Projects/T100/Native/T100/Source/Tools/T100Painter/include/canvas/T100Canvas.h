#ifndef T100CANVAS_H
#define T100CANVAS_H

#include <wx/scrolwin.h>
#include "T100Common.h"

class T100Canvas : public wxScrolledWindow
{
    public:
        T100Canvas(wxWindow *parent,
                     wxWindowID winid = wxID_ANY,
                     const wxPoint& pos = wxDefaultPosition,
                     const wxSize& size = wxDefaultSize,
                     long style = wxScrolledWindowStyle,
                     const wxString& name = wxPanelNameStr);
        virtual ~T100Canvas();

    protected:

    private:

        DECLARE_EVENT_TABLE()
};

#endif // T100CANVAS_H
