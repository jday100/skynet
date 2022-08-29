#ifndef T100VPCHARDWAREDIALOG_H
#define T100VPCHARDWAREDIALOG_H

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include "T100Common.h"


class T100VPCHardwareDialog : public wxDialog
{
    public:
        T100VPCHardwareDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHardwareDialog();

    private:
        T100VOID            create();
        T100VOID            destroy();

    protected:
		wxButton*           AppendButton;
		wxButton*           RemoveButton;
		wxButton*           CloseButton;
		wxListView*         HardwareListView;
		wxImageList*        ImageList;


    private:
        T100INT             m_index         = -1;

		static const long ID_LISTVIEW_HARDWARE;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		static const long ID_BUTTON_CLOSE;

    protected:
        T100BOOL            init();
        T100BOOL            load();

		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		void OnCloseButtonClick(wxCommandEvent& event);
		void OnHardwareListViewItemSelect(wxListEvent& event);

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCHARDWAREDIALOG_H
