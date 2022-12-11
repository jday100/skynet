#ifndef T100VPCCONFIGHARDWAREAPPENDDEMODIALOG_H
#define T100VPCCONFIGHARDWAREAPPENDDEMODIALOG_H

//(*Headers(T100VPCConfigHardwareAppendDemoDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class T100VPCConfigHardwareAppendDemoDialog: public wxDialog
{
	public:

		T100VPCConfigHardwareAppendDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCConfigHardwareAppendDemoDialog();

		//(*Declarations(T100VPCConfigHardwareAppendDemoDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxImageList* ImageList1;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100VPCConfigHardwareAppendDemoDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(T100VPCConfigHardwareAppendDemoDialog)
		void OnListView1ItemSelect(wxListEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
