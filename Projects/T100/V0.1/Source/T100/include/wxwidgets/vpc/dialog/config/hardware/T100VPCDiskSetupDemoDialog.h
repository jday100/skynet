#ifndef T100VPCDISKSETUPDEMODIALOG_H
#define T100VPCDISKSETUPDEMODIALOG_H

//(*Headers(T100VPCDiskSetupDemoDialog)
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class T100VPCDiskSetupDemoDialog: public wxDialog
{
	public:

		T100VPCDiskSetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDiskSetupDemoDialog();

		//(*Declarations(T100VPCDiskSetupDemoDialog)
		wxComboBox* FileLengthComboBox;
		wxComboBox* FilePathComboBox;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* FileNameTextCtrl;
		//*)

	protected:

		//(*Identifiers(T100VPCDiskSetupDemoDialog)
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_FILE_NAME;
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE_PATH;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_FILE_LENGTH;
		//*)

	private:

		//(*Handlers(T100VPCDiskSetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
