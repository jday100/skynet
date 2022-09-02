#ifndef T100VDISKNEWDEMODIALOG_H
#define T100VDISKNEWDEMODIALOG_H

//(*Headers(T100VDiskNewDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VDiskNewDemoDialog: public wxDialog
{
	public:

		T100VDiskNewDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VDiskNewDemoDialog();

		//(*Declarations(T100VDiskNewDemoDialog)
		wxButton* BrowseButton;
		wxComboBox* FileComboBox;
		wxComboBox* LengthComboBox;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(T100VDiskNewDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_LENGTH;
		//*)

	private:

		//(*Handlers(T100VDiskNewDemoDialog)
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
