#ifndef T100DISKCREATEDEMODIALOG_H
#define T100DISKCREATEDEMODIALOG_H

//(*Headers(T100DiskCreateDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class T100DiskCreateDemoDialog: public wxDialog
{
	public:

		T100DiskCreateDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskCreateDemoDialog();

		//(*Declarations(T100DiskCreateDemoDialog)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(T100DiskCreateDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;
		//*)

	private:

		//(*Handlers(T100DiskCreateDemoDialog)
		void OnButton1Click(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
