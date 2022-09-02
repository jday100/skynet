#ifndef T100FILESYSTEMCTRL_H
#define T100FILESYSTEMCTRL_H

#include <wx/wx.h>
#include <wx/generic/dirctrlg.h>


class T100FileSystemCtrl : public wxGenericDirCtrl
{
    public:
        T100FileSystemCtrl(wxWindow *parent, const wxWindowID id = wxID_ANY,
              const wxString &dir = wxDirDialogDefaultFolderStr,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = wxDIRCTRL_3D_INTERNAL,
              const wxString& filter = wxEmptyString,
              int defaultFilter = 0,
              const wxString& name = wxTreeCtrlNameStr);
        virtual ~T100FileSystemCtrl();

    protected:

    private:
};

#endif // T100FILESYSTEMCTRL_H
