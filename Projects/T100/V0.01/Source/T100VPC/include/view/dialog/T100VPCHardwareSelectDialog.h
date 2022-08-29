#ifndef T100VPCHARDWARESELECTDIALOG_H
#define T100VPCHARDWARESELECTDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include "T100Common.h"
#include "T100DiskInfo.h"
#include "T100DisplayInfo.h"
#include "T100KeyboardInfo.h"
#include "T100MouseInfo.h"


class T100VPCHardwareSelectDialog : public wxDialog
{
    public:
        T100VPCHardwareSelectDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHardwareSelectDialog();

    protected:
        T100INT             m_index         = -1;

		wxButton*           AppendButton;
		wxButton*           CloseButton;
		wxButton*           SettingButton;
		wxListView*         DeviceListView;

		T100DiskInfo        m_disk_info;
		T100DisplayInfo     m_display_info;
		T100KeyboardInfo    m_keyboard_info;
		T100MouseInfo       m_mouse_info;

    private:
        T100VOID            create();
        T100VOID            destroy();
        T100VOID            init();

		static const long ID_LISTVIEW_DEVICE;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_SETTING;
		static const long ID_BUTTON_CLOSE;

    protected:
        void OnCloseButtonClick(wxCommandEvent& event);
		void OnSettingButtonClick(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCHARDWARESELECTDIALOG_H
