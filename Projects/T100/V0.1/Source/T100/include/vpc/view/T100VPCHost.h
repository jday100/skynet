#ifndef T100VPCHOST_H
#define T100VPCHOST_H

#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>

namespace T100VPC{

class T100VPCHost : public wxFrame
{
    public:
        T100VPCHost(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCHost();

    protected:

    private:
        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCHOST_H
