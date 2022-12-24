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
		wxButton* CallButton;
		wxButton* NextButton;
		wxButton* PauseButton;
		wxButton* ReturnButton;
		wxButton* RunButton;
		wxButton* StepButton;
		wxComboBox* AARComboBox;
		wxComboBox* ABRComboBox;
		wxComboBox* ACFComboBox;
		wxComboBox* ACRComboBox;
		wxComboBox* ADRComboBox;
		wxComboBox* AMFComboBox;
		wxComboBox* AOFComboBox;
		wxComboBox* CBRComboBox;
		wxComboBox* CCRComboBox;
		wxComboBox* CORComboBox;
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
		wxComboBox* MemoryOffsetComboBox;
		wxComboBox* PortOffsetComboBox;
		wxListView* MemoryListView;
		wxListView* PortListView;
		wxScrollBar* MemoryScrollBar;
		wxScrollBar* PortScrollBar;
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
		static const long ID_COMBOBOX_COR;
		static const long ID_STATICTEXT15;
		static const long ID_COMBOBOX3;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_CBR;
		static const long ID_STATICTEXT16;
		static const long ID_COMBOBOX4;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_CCR;
		static const long ID_STATICTEXT17;
		static const long ID_COMBOBOX5;
		static const long ID_STATICTEXT18;
		static const long ID_COMBOBOX6;
		static const long ID_STATICTEXT19;
		static const long ID_COMBOBOX7;
		static const long ID_STATICTEXT20;
		static const long ID_COMBOBOX8;
		static const long ID_STATICTEXT21;
		static const long ID_COMBOBOX9;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX_AAR;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX_ACF;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX_ABR;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX_AMF;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX_ACR;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX_AOF;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX_ADR;
		static const long ID_STATICTEXT22;
		static const long ID_COMBOBOX10;
		static const long ID_STATICTEXT23;
		static const long ID_COMBOBOX11;
		static const long ID_STATICTEXT24;
		static const long ID_COMBOBOX13;
		static const long ID_STATICTEXT11;
		static const long ID_COMBOBOX_MEMORY_OFFSET;
		static const long ID_COMBOBOX12;
		static const long ID_STATICTEXT12;
		static const long ID_COMBOBOX1;
		static const long ID_LISTVIEW_MEMORY;
		static const long ID_SCROLLBAR_MEMORY;
		static const long ID_STATICTEXT13;
		static const long ID_COMBOBOX_PORT_OFFSET;
		static const long ID_COMBOBOX14;
		static const long ID_STATICTEXT14;
		static const long ID_COMBOBOX2;
		static const long ID_LISTVIEW_PORT;
		static const long ID_SCROLLBAR_PORT;
		static const long ID_BUTTON_RUN;
		static const long ID_BUTTON_STEP;
		static const long ID_BUTTON3;
		static const long ID_BUTTON_CALL;
		static const long ID_BUTTON_RETURN;
		static const long ID_BUTTON_PAUSE;
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
