#ifndef T100DISKCREATEPARTDEMODIALOG_H
#define T100DISKCREATEPARTDEMODIALOG_H

//(*Headers(T100DiskCreatePartDemoDialog)
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
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
		wxCheckBox* CheckBox1;
		wxComboBox* ComboBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(T100DiskCreatePartDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;
		static const long ID_CHECKBOX1;
		//*)

	private:

		//(*Handlers(T100DiskCreatePartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
