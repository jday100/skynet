#ifndef T100CREATEDIALOG_H
#define T100CREATEDIALOG_H

//(*Headers(T100CreateDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class T100CreateDialog: public wxDialog
{
	public:

		T100CreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~T100CreateDialog();

		//(*Declarations(T100CreateDialog)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxRadioButton* RadioButton1;
		wxRadioButton* RadioButton2;
		wxRadioButton* RadioButton3;
		wxRadioButton* RadioButton4;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

    private:
        void OnButtonApplyClick(wxCommandEvent& event);

	protected:

		//(*Identifiers(T100CreateDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_RADIOBUTTON3;
		static const long ID_RADIOBUTTON4;
		//*)

	private:

		//(*Handlers(T100CreateDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
