#ifndef T100DISKCREATEPARTDEMODIALOG_H
#define T100DISKCREATEPARTDEMODIALOG_H

//(*Headers(T100DiskCreatePartDemoDialog)
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class T100DiskCreatePartDemoDialog: public wxDialog
{
	public:

		T100DiskCreatePartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskCreatePartDemoDialog();

		//(*Declarations(T100DiskCreatePartDemoDialog)
		wxCheckBox* BootCheckBox;
		wxComboBox* LengthComboBox;
		wxComboBox* LocationComboBox;
		wxComboBox* TypeComboBox;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* NameTextCtrl;
		//*)

	protected:

		//(*Identifiers(T100DiskCreatePartDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_NAME;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_LOCATION;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_LENGTH;
		static const long ID_CHECKBOX_BOOT;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX_TYPE;
		//*)

	private:

		//(*Handlers(T100DiskCreatePartDemoDialog)
		void OnNameTextCtrlText(wxCommandEvent& event);
		void OnNameTextCtrlTextEnter(wxCommandEvent& event);
		void OnLocationComboBoxSelected(wxCommandEvent& event);
		void OnLocationComboBoxTextUpdated(wxCommandEvent& event);
		void OnLocationComboBoxTextEnter(wxCommandEvent& event);
		void OnLengthComboBoxSelected(wxCommandEvent& event);
		void OnLengthComboBoxTextUpdated(wxCommandEvent& event);
		void OnLengthComboBoxTextEnter(wxCommandEvent& event);
		void OnBootCheckBoxClick(wxCommandEvent& event);
		void OnTypeComboBoxSelected(wxCommandEvent& event);
		void OnTypeComboBoxTextUpdated(wxCommandEvent& event);
		void OnTypeComboBoxTextEnter(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
