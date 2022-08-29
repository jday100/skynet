#ifndef T100VPCDEBUGDEMODIALOG_H
#define T100VPCDEBUGDEMODIALOG_H

//(*Headers(T100VPCDebugDemoDialog)
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/scrolbar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VPCDebugDemoDialog: public wxDialog
{
	public:

		T100VPCDebugDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDebugDemoDialog();

		//(*Declarations(T100VPCDebugDemoDialog)
		wxComboBox* ComboBox10;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox6;
		wxComboBox* ComboBox7;
		wxComboBox* ComboBox8;
		wxComboBox* ComboBox9;
		wxListCtrl* ListCtrl1;
		wxListCtrl* ListCtrl2;
		wxScrollBar* ScrollBar1;
		wxScrollBar* ScrollBar2;
		wxStaticText* StaticText10;
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

		//(*Identifiers(T100VPCDebugDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX3;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX2;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX4;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX5;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX10;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX6;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX8;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX9;
		static const long ID_LISTCTRL1;
		static const long ID_SCROLLBAR1;
		static const long ID_LISTCTRL2;
		static const long ID_SCROLLBAR2;
		//*)

	private:

		//(*Handlers(T100VPCDebugDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
