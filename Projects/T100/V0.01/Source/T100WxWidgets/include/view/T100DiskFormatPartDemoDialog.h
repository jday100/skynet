#ifndef T100DISKFORMATPARTDEMODIALOG_H
#define T100DISKFORMATPARTDEMODIALOG_H

//(*Headers(T100DiskFormatPartDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100DiskFormatPartDemoDialog: public wxDialog
{
	public:

		T100DiskFormatPartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskFormatPartDemoDialog();

		//(*Declarations(T100DiskFormatPartDemoDialog)
		wxButton* Button1;
		wxComboBox* ComboBox1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(T100DiskFormatPartDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(T100DiskFormatPartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
