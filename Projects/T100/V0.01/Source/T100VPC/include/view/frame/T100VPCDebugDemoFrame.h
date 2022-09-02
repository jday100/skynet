#ifndef T100VPCDEBUGDEMOFRAME_H
#define T100VPCDEBUGDEMOFRAME_H

//(*Headers(T100VPCDebugDemoFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/scrolbar.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VPCDebugDemoFrame: public wxFrame
{
	public:

		T100VPCDebugDemoFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDebugDemoFrame();

		//(*Declarations(T100VPCDebugDemoFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxComboBox* ComboBox10;
		wxComboBox* ComboBox11;
		wxComboBox* ComboBox12;
		wxComboBox* ComboBox13;
		wxComboBox* ComboBox14;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox6;
		wxComboBox* ComboBox7;
		wxComboBox* ComboBox8;
		wxComboBox* ComboBox9;
		wxListView* ListView1;
		wxListView* ListView2;
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

		//(*Identifiers(T100VPCDebugDemoFrame)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX2;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX3;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX4;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX5;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX6;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX8;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX9;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX10;
		static const long ID_COMBOBOX11;
		static const long ID_COMBOBOX12;
		static const long ID_LISTVIEW1;
		static const long ID_SCROLLBAR1;
		static const long ID_COMBOBOX13;
		static const long ID_COMBOBOX14;
		static const long ID_LISTVIEW2;
		static const long ID_SCROLLBAR2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		//*)

	private:

		//(*Handlers(T100VPCDebugDemoFrame)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
