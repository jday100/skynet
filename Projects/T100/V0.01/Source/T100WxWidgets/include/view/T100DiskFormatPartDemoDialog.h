#ifndef T100DISKFORMATPARTDEMODIALOG_H
#define T100DISKFORMATPARTDEMODIALOG_H

//(*Headers(T100DiskFormatPartDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100DiskFormatPartDemoDialog: public wxDialog
{
	public:

		T100DiskFormatPartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskFormatPartDemoDialog();

		//(*Declarations(T100DiskFormatPartDemoDialog)
		wxButton* BrowseButton;
		wxComboBox* FileComboBox;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(T100DiskFormatPartDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		//*)

	private:

		//(*Handlers(T100DiskFormatPartDemoDialog)
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
