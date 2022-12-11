#ifndef T100VPCCONFIGHARDWAREAPPENDDIALOG_H
#define T100VPCCONFIGHARDWAREAPPENDDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>

#include "T100Common.h"
#include "T100VPCAllDevices.h"

namespace T100VPC{

class T100VPCConfigHardwareAppendDialog : public wxDialog
{
    public:
        T100VPCConfigHardwareAppendDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCConfigHardwareAppendDialog();

        wxImageList*            ImageList;
        wxListView*             ListView;
        wxButton*               AppendButton;
        wxButton*               FinishButton;

    protected:
        static const long ID_LISTVIEW;
        static const long ID_BUTTON_APPEND;
        static const long ID_BUTTON_FINISH;

    private:
        void OnListViewItemSelect(wxListEvent& event);
        void OnButtonAppendClick(wxCommandEvent& event);
        void OnButtonFinishClick(wxCommandEvent& event);

    private:
        T100CUDeviceInfo*       m_cu            = T100NULL;
        T100AUDeviceInfo*       m_au            = T100NULL;
        T100MemoryInfo*         m_memory        = T100NULL;
        T100PortDeviceInfo*     m_port          = T100NULL;

        T100DisplayInfo*        m_display       = T100NULL;
        T100DiskInfo*           m_disk          = T100NULL;
        T100KeyboardInfo*       m_keyboard      = T100NULL;
        T100MouseInfo*          m_mouse         = T100NULL;

        T100DeviceInfo*         m_current       = T100NULL;

    private:
        T100VOID                load();

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCCONFIGHARDWAREAPPENDDIALOG_H
