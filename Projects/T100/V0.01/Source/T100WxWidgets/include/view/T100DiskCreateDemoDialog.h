#ifndef T100DISKCREATEDEMODIALOG_H
#define T100DISKCREATEDEMODIALOG_H

//(*Headers(T100DiskCreateDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100DiskCreateDemoDialog: public wxDialog
{
	public:

		T100DiskCreateDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskCreateDemoDialog();

		//(*Declarations(T100DiskCreateDemoDialog)
		wxButton* BrowseButton;
		wxComboBox* FileComboBox;
		wxComboBox* LengthComboBox;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(T100DiskCreateDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_LENGTH;
		//*)

	private:

		//(*Handlers(T100DiskCreateDemoDialog)
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);
		void OnLengthComboBoxSelected(wxCommandEvent& event);
		void OnLengthComboBoxTextUpdated(wxCommandEvent& event);
		void OnLengthComboBoxTextEnter(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
