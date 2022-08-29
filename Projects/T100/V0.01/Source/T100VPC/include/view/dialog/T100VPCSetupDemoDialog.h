#ifndef T100VPCSETUPDEMODIALOG_H
#define T100VPCSETUPDEMODIALOG_H

//(*Headers(T100VPCSetupDemoDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VPCSetupDemoDialog: public wxDialog
{
	public:

		T100VPCSetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCSetupDemoDialog();

		//(*Declarations(T100VPCSetupDemoDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox6;
		wxComboBox* ComboBox7;
		wxComboBox* ComboBox8;
		wxComboBox* ComboBox9;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		//*)

	protected:

		//(*Identifiers(T100VPCSetupDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX2;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX4;
		static const long ID_COMBOBOX5;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX6;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX8;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX9;
		//*)

	private:

		//(*Handlers(T100VPCSetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
