#ifndef T100VPCCONFIGHARDWAREDEMODIALOG_H
#define T100VPCCONFIGHARDWAREDEMODIALOG_H

//(*Headers(T100VPCConfigHardwareDemoDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
//*)

class T100VPCConfigHardwareDemoDialog: public wxDialog
{
	public:

		T100VPCConfigHardwareDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCConfigHardwareDemoDialog();

		//(*Declarations(T100VPCConfigHardwareDemoDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxImageList* ImageList1;
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100VPCConfigHardwareDemoDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(T100VPCConfigHardwareDemoDialog)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
