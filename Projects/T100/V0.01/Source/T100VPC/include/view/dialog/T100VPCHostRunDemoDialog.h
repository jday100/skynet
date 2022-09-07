#ifndef T100VPCHOSTRUNDEMODIALOG_H
#define T100VPCHOSTRUNDEMODIALOG_H

//(*Headers(T100VPCHostRunDemoDialog)
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class T100VPCHostRunDemoDialog: public wxDialog
{
	public:

		T100VPCHostRunDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCHostRunDemoDialog();

		//(*Declarations(T100VPCHostRunDemoDialog)
		wxComboBox* ComboBoxBase;
		wxComboBox* ComboBoxOffset;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(T100VPCHostRunDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_BASE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_OFFSET;
		//*)

	private:

		//(*Handlers(T100VPCHostRunDemoDialog)
		void OnComboBoxBaseSelected(wxCommandEvent& event);
		void OnComboBoxBaseTextUpdated(wxCommandEvent& event);
		void OnComboBoxBaseTextEnter(wxCommandEvent& event);
		void OnComboBoxOffsetSelected(wxCommandEvent& event);
		void OnComboBoxOffsetTextUpdated(wxCommandEvent& event);
		void OnComboBoxOffsetTextEnter(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
