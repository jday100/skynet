#ifndef T100VPCPANEL_H
#define T100VPCPANEL_H

#include <wx/panel.h>
#include "T100Common.h"

namespace T100VPC{
class T100VPCDisplay;

class T100VPCPanel : public wxPanel
{
    public:
        T100VPCPanel(T100VPCDisplay* display, wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCPanel();

    protected:
        void OnPaint(wxPaintEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
        void OnChar(wxKeyEvent& event);
        void OnMouseMove(wxMouseEvent& event);

    private:
        T100VPCDisplay*         m_diaplay           = T100NULL;

        T100BOOL                paint();

        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCPANEL_H
