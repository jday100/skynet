#ifndef T100WXDISKLIST_H
#define T100WXDISKLIST_H

#include <wx/listctrl.h>

class T100WxDiskList : public wxListCtrl
{
    public:
        T100WxDiskList(wxWindow *parent,
               wxWindowID id = wxID_ANY,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxLC_ICON,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxListCtrlNameStr);
        virtual ~T100WxDiskList();

    protected:

    private:
};

#endif // T100WXDISKLIST_H
