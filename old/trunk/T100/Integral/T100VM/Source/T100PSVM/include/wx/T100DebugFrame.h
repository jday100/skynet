#ifndef T100DEBUGFRAME_H
#define T100DEBUGFRAME_H

//(*Headers(T100DebugFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#include "T100Common.h"

class T100VM;

class T100DebugFrame: public wxFrame
{
	public:

		T100DebugFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DebugFrame();

		//(*Declarations(T100DebugFrame)
		wxButton* Button2;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* Button8;
		wxButton* ButtonRun;
		wxButton* ButtonStepIn;
		wxComboBox* ComboBox16;
		wxComboBox* ComboBoxCS;
		wxComboBox* ComboBoxDS;
		wxComboBox* ComboBoxEFER;
		wxComboBox* ComboBoxEFLAGS;
		wxComboBox* ComboBoxES;
		wxComboBox* ComboBoxFS;
		wxComboBox* ComboBoxFSBase;
		wxComboBox* ComboBoxGS;
		wxComboBox* ComboBoxGSBase;
		wxComboBox* ComboBoxKGSBase;
		wxComboBox* ComboBoxMXCSR;
		wxComboBox* ComboBoxR10;
		wxComboBox* ComboBoxR11;
		wxComboBox* ComboBoxR12;
		wxComboBox* ComboBoxR13;
		wxComboBox* ComboBoxR14;
		wxComboBox* ComboBoxR15;
		wxComboBox* ComboBoxR8;
		wxComboBox* ComboBoxR9;
		wxComboBox* ComboBoxRAX;
		wxComboBox* ComboBoxRBP;
		wxComboBox* ComboBoxRBX;
		wxComboBox* ComboBoxRCX;
		wxComboBox* ComboBoxRDI;
		wxComboBox* ComboBoxRDX;
		wxComboBox* ComboBoxRIP;
		wxComboBox* ComboBoxRSI;
		wxComboBox* ComboBoxRSP;
		wxComboBox* ComboBoxSS;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxStaticText* StaticText16;
		wxStaticText* StaticText17;
		wxStaticText* StaticText18;
		wxStaticText* StaticText19;
		wxStaticText* StaticText1;
		wxStaticText* StaticText20;
		wxStaticText* StaticText21;
		wxStaticText* StaticText22;
		wxStaticText* StaticText23;
		wxStaticText* StaticText24;
		wxStaticText* StaticText25;
		wxStaticText* StaticText26;
		wxStaticText* StaticText27;
		wxStaticText* StaticText28;
		wxStaticText* StaticText29;
		wxStaticText* StaticText2;
		wxStaticText* StaticText30;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		//*)

		T100VOID            SetVM(T100VM*);
		T100VM*             GetVM();

	protected:

		//(*Identifiers(T100DebugFrame)
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
		static const long ID_STATICTEXT11;
		static const long ID_COMBOBOX11;
		static const long ID_STATICTEXT12;
		static const long ID_COMBOBOX12;
		static const long ID_STATICTEXT13;
		static const long ID_COMBOBOX13;
		static const long ID_STATICTEXT14;
		static const long ID_COMBOBOX14;
		static const long ID_STATICTEXT15;
		static const long ID_COMBOBOX15;
		static const long ID_STATICTEXT16;
		static const long ID_COMBOBOX16;
		static const long ID_STATICTEXT17;
		static const long ID_COMBOBOX17;
		static const long ID_STATICTEXT18;
		static const long ID_COMBOBOX18;
		static const long ID_STATICTEXT19;
		static const long ID_COMBOBOX19;
		static const long ID_STATICTEXT20;
		static const long ID_COMBOBOX20;
		static const long ID_STATICTEXT21;
		static const long ID_COMBOBOX21;
		static const long ID_STATICTEXT22;
		static const long ID_COMBOBOX22;
		static const long ID_STATICTEXT23;
		static const long ID_COMBOBOX23;
		static const long ID_STATICTEXT24;
		static const long ID_COMBOBOX24;
		static const long ID_STATICTEXT25;
		static const long ID_COMBOBOX25;
		static const long ID_STATICTEXT26;
		static const long ID_COMBOBOX26;
		static const long ID_STATICTEXT27;
		static const long ID_COMBOBOX27;
		static const long ID_STATICTEXT28;
		static const long ID_COMBOBOX28;
		static const long ID_STATICTEXT29;
		static const long ID_COMBOBOX29;
		static const long ID_STATICTEXT30;
		static const long ID_COMBOBOX30;
		static const long ID_BUTTON_RUN;
		static const long ID_BUTTON2;
		static const long ID_BUTTON_STEP_IN;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		//*)

	private:

		//(*Handlers(T100DebugFrame)
		void OnButtonRunClick(wxCommandEvent& event);
		void OnButtonStepInClick(wxCommandEvent& event);
		//*)

	protected:
	    T100VM*             m_vm        = T100NULL;

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
