#ifndef T100VPCDISPLAYSETUPDEMODIALOG_H
#define T100VPCDISPLAYSETUPDEMODIALOG_H

//(*Headers(T100VPCDisplaySetupDemoDialog)
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VPCDisplaySetupDemoDialog: public wxDialog
{
	public:

		T100VPCDisplaySetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDisplaySetupDemoDialog();

		//(*Declarations(T100VPCDisplaySetupDemoDialog)
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		//*)

	protected:

		//(*Identifiers(T100VPCDisplaySetupDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX2;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX3;
		//*)

	private:

		//(*Handlers(T100VPCDisplaySetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
