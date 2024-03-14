#ifndef T100PAINTCTRL_H
#define T100PAINTCTRL_H

#include <wx/control.h>
#include "T100PaintCanvas.h"


class T100PaintCtrl : public wxControl
{
    public:
        T100PaintCtrl(wxWindow *parent, wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize, long style = 0,
              const wxValidator& validator = wxDefaultValidator,
              const wxString& name = wxControlNameStr);
        virtual ~T100PaintCtrl();

    protected:
        void                        create();
        void                        destroy();

    private:
        T100PaintCanvas*            m_canvas            = nullptr;
};

#endif // T100PAINTCTRL_H
