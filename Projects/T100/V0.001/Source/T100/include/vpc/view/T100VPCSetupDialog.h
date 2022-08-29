#ifndef T100VPCSETUPDIALOG_H
#define T100VPCSETUPDIALOG_H

//(*Headers(T100VPCSetupDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
//*)
#include "T100VPCCommon.h"


class T100VPCSetupDialog: public wxDialog
{
	public:

		T100VPCSetupDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCSetupDialog();

		//(*Declarations(T100VPCSetupDialog)
		wxButton* OKButton;
		wxComboBox* FontFileComboBox;
		wxComboBox* RamSizeComboBox;
		wxComboBox* RomFileComboBox;
		wxComboBox* RomSizeComboBox;
		wxComboBox* VDiskFileComboBox;
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		//*)

	protected:

		//(*Identifiers(T100VPCSetupDialog)
		static const long ID_STATICBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX2;
		static const long ID_PANEL1;
		static const long ID_STATICBOX2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX3;
		static const long ID_COMBOBOX4;
		static const long ID_COMBOBOX5;
		static const long ID_PANEL2;
		static const long ID_BUTTON1;
		//*)

	private:
	    T100VOID            create();
	    T100VOID            destroy();

		//(*Handlers(T100VPCSetupDialog)
		void OnRomSizeComboBoxSelected(wxCommandEvent& event);
		void OnRomSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnRamSizeComboBoxSelected(wxCommandEvent& event);
		void OnRamSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnRomFileComboBoxSelected(wxCommandEvent& event);
		void OnRomFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFontFileComboBoxSelected(wxCommandEvent& event);
		void OnFontFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnVDiskFileComboBoxSelected(wxCommandEvent& event);
		void OnVDiskFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnOKButtonClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
