#ifndef T100VPCDEBUGFRAME_H
#define T100VPCDEBUGFRAME_H

//(*Headers(T100VPCDebugFrame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
//*)
#include "T100VPCCommon.h"
#include "T100Memory32.h"
class T100VPCServe;
class T100VPCView;


class T100VPCDebugFrame: public wxFrame
{
	public:

		T100VPCDebugFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCDebugFrame();

		T100VOID            setView(T100VPCView*);
		T100VPCView*        getView();

		T100BOOL            start();
		T100BOOL            stop();

		T100BOOL            load();
		T100BOOL            update();

		T100BOOL            updateRom(wxString);
		T100BOOL            updateRam(wxString);
		T100BOOL            updateDevice();
		T100BOOL            updateBlock(wxString);
		T100BOOL            updatePage(wxString);


		//(*Declarations(T100VPCDebugFrame)
		wxButton* NextButton;
		wxButton* PauseButton;
		wxButton* RunButton;
		wxButton* StepButton;
		wxComboBox* ComboBoxAAR;
		wxComboBox* ComboBoxABR;
		wxComboBox* ComboBoxACF;
		wxComboBox* ComboBoxACR;
		wxComboBox* ComboBoxADR;
		wxComboBox* ComboBoxAMF;
		wxComboBox* ComboBoxAOF;
		wxComboBox* ComboBoxBlockBase;
		wxComboBox* ComboBoxCBR;
		wxComboBox* ComboBoxCCR;
		wxComboBox* ComboBoxCOR;
		wxComboBox* ComboBoxPageBase;
		wxComboBox* ComboBoxRamBase;
		wxComboBox* ComboBoxRomBase;
		wxListCtrl* ListCtrlBlock;
		wxListCtrl* ListCtrlDevice;
		wxListCtrl* ListCtrlPage;
		wxListCtrl* ListCtrlRam;
		wxListCtrl* ListCtrlRom;
		wxMenu* Menu1;
		wxMenuBar* MenuBar;
		wxMenuItem* MenuLogOff;
		wxMenuItem* MenuLogOn;
		wxStaticBox* StaticBox10;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticBox* StaticBox4;
		wxStaticBox* StaticBox5;
		wxStaticBox* StaticBox6;
		wxStaticBox* StaticBox7;
		wxStaticBox* StaticBox8;
		wxStaticBox* StaticBox9;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		//*)

	protected:
	    T100VPCView*        m_view      = T100NULL;

		//(*Identifiers(T100VPCDebugFrame)
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX3;
		static const long ID_STATICBOX2;
		static const long ID_BUTTON_STEP;
		static const long ID_BUTTON_RUN;
		static const long ID_STATICBOX4;
		static const long ID_STATICBOX5;
		static const long ID_STATICBOX6;
		static const long ID_STATICBOX7;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_LISTCTRL_ROM;
		static const long ID_LISTCTRL_RAM;
		static const long ID_STATICBOX8;
		static const long ID_STATICBOX9;
		static const long ID_LISTCTRL_DEVICE;
		static const long ID_LISTCTRL_BLOCK;
		static const long ID_STATICBOX10;
		static const long ID_LISTCTRL_PAGE;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_COMBOBOX_COR;
		static const long ID_COMBOBOX_CBR;
		static const long ID_COMBOBOX_CCR;
		static const long ID_COMBOBOX_AAR;
		static const long ID_COMBOBOX_ABR;
		static const long ID_COMBOBOX_ACR;
		static const long ID_COMBOBOX_ADR;
		static const long ID_COMBOBOX_ACF;
		static const long ID_COMBOBOX_AMF;
		static const long ID_COMBOBOX_AOF;
		static const long ID_COMBOBOX_ROM_BASE;
		static const long ID_COMBOBOX_RAM_BASE;
		static const long ID_COMBOBOX_BLOCK_BASE;
		static const long ID_COMBOBOX_PAGE_BASE;
		static const long ID_BUTTON_NEXT;
		static const long ID_BUTTON_PAUSE;
		static const long ID_MENUITEM_LOG_ON;
		static const long ID_MENUITEM_LOG_OFF;
		//*)

	private:
	    T100VOID            load(T100VPCServe*);
	    T100VOID            update(T100VPCServe*);
	    T100VOID            update(T100Memory32*);


		//(*Handlers(T100VPCDebugFrame)
		void OnStepButtonClick(wxCommandEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnComboBoxRomBaseSelected(wxCommandEvent& event);
		void OnComboBoxRomBaseTextUpdated(wxCommandEvent& event);
		void OnComboBoxRamBaseSelected(wxCommandEvent& event);
		void OnComboBoxRamBaseTextUpdated(wxCommandEvent& event);
		void OnComboBoxBlockBaseSelected(wxCommandEvent& event);
		void OnComboBoxBlockBaseTextUpdated(wxCommandEvent& event);
		void OnComboBoxPageBaseSelected(wxCommandEvent& event);
		void OnComboBoxPageBaseTextUpdated(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnNextButtonClick(wxCommandEvent& event);
		void OnPauseButtonClick(wxCommandEvent& event);
		void OnMenuLogOffSelected(wxCommandEvent& event);
		void OnMenuLogOnSelected(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
