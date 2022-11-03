#ifndef T100FONTPANEL_H
#define T100FONTPANEL_H

//(*Headers(T100FontPanel)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
//*)

#include <atomic>
#include "T100Common.h"
#include "T100FontTools.h"


namespace T100FontBuilder{

class T100FontPanel: public wxPanel
{
	public:

		T100FontPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100FontPanel();

		//(*Declarations(T100FontPanel)
		wxButton* AppendButton;
		wxButton* BrowseButton;
		wxButton* RemoveButton;
		wxButton* RunButton;
		wxChoice* FontNameChoice;
		wxComboBox* CodeBeginComboBox;
		wxComboBox* CodeEndComboBox;
		wxComboBox* FileComboBox;
		wxComboBox* FontSizeComboBox;
		wxListBox* CountryListBox;
		wxListCtrl* FontCodeListCtrl;
		wxPanel* PaintPanel;
		wxRadioButton* NameCodeRadioButton1;
		wxRadioButton* NameCodeRadioButton2;
		wxStaticBox* StaticBox1;
		wxStaticBox* StaticBox2;
		wxStaticBox* StaticBox3;
		wxStaticBox* StaticBox4;
		//*)

	protected:

		//(*Identifiers(T100FontPanel)
		static const long ID_STATICBOX1;
		static const long ID_STATICBOX2;
		static const long ID_STATICBOX3;
		static const long ID_STATICBOX4;
		static const long ID_CHOICE_FONT_NAME;
		static const long ID_RADIOBUTTON_NAMECODE1;
		static const long ID_RADIOBUTTON_NAMECODE2;
		static const long ID_COMBOBOX_FONT_SIZE;
		static const long ID_LISTBOX_COUNTRY;
		static const long ID_LISTCTRL_FONT_CODE;
		static const long ID_COMBOBOX_CODE_BEGIN;
		static const long ID_COMBOBOX_CODE_END;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_BUTTON_RUN;
		static const long ID_PANEL_PAINT;
		//*)

	private:
	    T100FontTools                   m_tools;
	    std::atomic_bool                m_running;
	    T100LONG                        m_current           = -1;

		//(*Handlers(T100FontPanel)
		void OnFontNameChoiceSelect(wxCommandEvent& event);
		void OnNameCodeRadioButton1Select(wxCommandEvent& event);
		void OnNameCodeRadioButton2Select(wxCommandEvent& event);
		void OnFontSizeComboBoxSelected(wxCommandEvent& event);
		void OnFontSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnFontSizeComboBoxTextEnter(wxCommandEvent& event);
		void OnCountryListBoxSelect(wxCommandEvent& event);
		void OnFontCodeListCtrlItemSelect(wxListEvent& event);
		void OnFontCodeListCtrlItemDeselect(wxListEvent& event);
		void OnCodeBeginComboBoxSelected(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextEnter(wxCommandEvent& event);
		void OnCodeEndComboBoxSelected(wxCommandEvent& event);
		void OnCodeEndComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeEndComboBoxTextEnter(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnPaintPanelPaint(wxPaintEvent& event);
		//*)

	protected:
	    T100VOID            create();
	    T100VOID            destroy();

	    T100BOOL            verify();

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
