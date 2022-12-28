#ifndef T100VPCDEBUGDEMOFRAME_H
#define T100VPCDEBUGDEMOFRAME_H

//(*Headers(T100VPCDebugDemoFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listbox.h>
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
		wxButton* Button7;
		wxButton* Button8;
		wxComboBox* ComboBox10;
		wxComboBox* ComboBox11;
		wxComboBox* ComboBox12;
		wxComboBox* ComboBox13;
		wxComboBox* ComboBox14;
		wxComboBox* ComboBox15;
		wxComboBox* ComboBox16;
		wxComboBox* ComboBox17;
		wxComboBox* ComboBox18;
		wxComboBox* ComboBox19;
		wxComboBox* ComboBox1;
		wxComboBox* ComboBox20;
		wxComboBox* ComboBox21;
		wxComboBox* ComboBox22;
		wxComboBox* ComboBox23;
		wxComboBox* ComboBox24;
		wxComboBox* ComboBox2;
		wxComboBox* ComboBox3;
		wxComboBox* ComboBox4;
		wxComboBox* ComboBox5;
		wxComboBox* ComboBox6;
		wxComboBox* ComboBox7;
		wxComboBox* ComboBox8;
		wxComboBox* ComboBox9;
		wxListBox* ListBox1;
		wxListBox* ListBox2;
		wxListView* ListView1;
		wxListView* ListView2;
		wxScrollBar* ScrollBar1;
		wxScrollBar* ScrollBar2;
		wxScrollBar* ScrollBar3;
		wxScrollBar* ScrollBar4;
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
		static const long ID_COMBOBOX20;
		static const long ID_STATICTEXT20;
		static const long ID_COMBOBOX21;
		static const long ID_LISTBOX1;
		static const long ID_SCROLLBAR1;
		static const long ID_LISTVIEW1;
		static const long ID_SCROLLBAR2;
		static const long ID_STATICTEXT21;
		static const long ID_COMBOBOX22;
		static const long ID_COMBOBOX23;
		static const long ID_STATICTEXT22;
		static const long ID_COMBOBOX24;
		static const long ID_LISTBOX2;
		static const long ID_SCROLLBAR3;
		static const long ID_LISTVIEW2;
		static const long ID_SCROLLBAR4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		//*)

	private:

		//(*Handlers(T100VPCDebugDemoFrame)
		void OnCORComboBoxSelected(wxCommandEvent& event);
		void OnCORComboBoxTextUpdated(wxCommandEvent& event);
		void OnCORComboBoxTextEnter(wxCommandEvent& event);
		void OnCBRComboBoxSelected(wxCommandEvent& event);
		void OnCBRComboBoxTextUpdated(wxCommandEvent& event);
		void OnCBRComboBoxTextEnter(wxCommandEvent& event);
		void OnCCRComboBoxSelected(wxCommandEvent& event);
		void OnCCRComboBoxTextUpdated(wxCommandEvent& event);
		void OnCCRComboBoxTextEnter(wxCommandEvent& event);
		void OnAARComboBoxSelected(wxCommandEvent& event);
		void OnAARComboBoxTextUpdated(wxCommandEvent& event);
		void OnAARComboBoxTextEnter(wxCommandEvent& event);
		void OnABRComboBoxSelected(wxCommandEvent& event);
		void OnABRComboBoxTextUpdated(wxCommandEvent& event);
		void OnABRComboBoxTextEnter(wxCommandEvent& event);
		void OnACRComboBoxSelected(wxCommandEvent& event);
		void OnACRComboBoxTextUpdated(wxCommandEvent& event);
		void OnACRComboBoxTextEnter(wxCommandEvent& event);
		void OnADRComboBoxSelected(wxCommandEvent& event);
		void OnADRComboBoxTextUpdated(wxCommandEvent& event);
		void OnADRComboBoxTextEnter(wxCommandEvent& event);
		void OnACFComboBoxSelected(wxCommandEvent& event);
		void OnACFComboBoxTextUpdated(wxCommandEvent& event);
		void OnACFComboBoxTextEnter(wxCommandEvent& event);
		void OnAMFComboBoxSelected(wxCommandEvent& event);
		void OnAMFComboBoxTextUpdated(wxCommandEvent& event);
		void OnAMFComboBoxTextEnter(wxCommandEvent& event);
		void OnAOFComboBoxSelected(wxCommandEvent& event);
		void OnAOFComboBoxTextUpdated(wxCommandEvent& event);
		void OnAOFComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxSelected(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxTextUpdated(wxCommandEvent& event);
		void OnMemoryOffsetComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryScrollBarScrollLineDown(wxScrollEvent& event);
		void OnMemoryScrollBarScrollPageUp(wxScrollEvent& event);
		void OnMemoryScrollBarScrollPageDown(wxScrollEvent& event);
		void OnMemoryScrollBarScrollChanged(wxScrollEvent& event);
		void OnPortOffsetComboBoxSelected(wxCommandEvent& event);
		void OnPortOffsetComboBoxTextUpdated(wxCommandEvent& event);
		void OnPortOffsetComboBoxTextEnter(wxCommandEvent& event);
		void OnMemoryScrollBarScrollLineUp(wxScrollEvent& event);
		void OnMemoryScrollBarScroll(wxScrollEvent& event);
		void OnMemoryScrollBarScrollTop(wxScrollEvent& event);
		void OnMemoryScrollBarScrollBottom(wxScrollEvent& event);
		void OnPortScrollBarScroll(wxScrollEvent& event);
		void OnPortScrollBarScrollTop(wxScrollEvent& event);
		void OnPortScrollBarScrollBottom(wxScrollEvent& event);
		void OnPortScrollBarScrollLineUp(wxScrollEvent& event);
		void OnPortScrollBarScrollLineDown(wxScrollEvent& event);
		void OnPortScrollBarScrollPageUp(wxScrollEvent& event);
		void OnPortScrollBarScrollPageDown(wxScrollEvent& event);
		void OnPortScrollBarScrollChanged(wxScrollEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnPauseButtonClick(wxCommandEvent& event);
		void OnStepButtonClick(wxCommandEvent& event);
		void OnNextButtonClick(wxCommandEvent& event);
		void OnCallButtonClick(wxCommandEvent& event);
		void OnReturnButtonClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
