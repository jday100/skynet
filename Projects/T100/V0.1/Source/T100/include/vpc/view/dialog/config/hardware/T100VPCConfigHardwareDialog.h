#ifndef T100VPCCONFIGHARDWAREDIALOG_H
#define T100VPCCONFIGHARDWAREDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>

#include "T100Common.h"
#include "T100VPCConfigHardwareAppendDialog.h"

namespace T100VPC{


class T100VPCConfigHardwareDialog : public wxDialog
{
    public:
        T100VPCConfigHardwareDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCConfigHardwareDialog();

        wxImageList*        ImageList;
        wxListView*         ListView;
        wxButton*           SetupButton;
        wxButton*           AppendButton;
        wxButton*           RemoveButton;
        wxButton*           FinishButton;

        T100VPCConfigHardwareAppendDialog*      getAppendDialog();

    protected:
        static const long ID_LISTVIEW;
        static const long ID_BUTTON_SETUP;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_REMOVE;
        static const long ID_BUTTON_FINISH;

    private:
        void OnButtonSetupClick(wxCommandEvent& event);
        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonRemoveClick(wxCommandEvent& event);
        void OnButtonFinishClick(wxCommandEvent& event);

    private:
        T100VPCConfigHardwareAppendDialog*      m_append_dialog         = T100NULL;

    private:
        T100BOOL            load();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

        DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCCONFIGHARDWAREDIALOG_H
