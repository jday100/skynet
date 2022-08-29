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

#include "T100FontCommon.h"
#include "T100FontTools.h"


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
		wxChoice* FontChoice;
		wxComboBox* CodeBeginComboBox;
		wxComboBox* CodeEndComboBox;
		wxComboBox* FileComboBox;
		wxComboBox* FontSizeComboBox;
		wxListBox* CountryListBox;
		wxListCtrl* FontCodeListCtrl;
		wxPanel* PaintPanel;
		wxRadioButton* NameCodeRadioButton1;
		wxRadioButton* NameCodeRadioButton2;
		wxStaticBox* FontCodeStaticBox;
		wxStaticBox* FontFileStaticBox;
		wxStaticBox* FontSizeStaticBox;
		wxStaticBox* FontStaticBox;
		//*)

	protected:

		//(*Identifiers(T100FontPanel)
		static const long ID_STATICBOX_FONT;
		static const long ID_STATICBOX_FONTSIZE;
		static const long ID_CHOICE_FONT;
		static const long ID_COMBOBOX_FONTSIZE;
		static const long ID_STATICBOX_FONTCODE;
		static const long ID_LISTCTRL_FONTCODE;
		static const long ID_COMBOBOX_CODEBEGIN;
		static const long ID_COMBOBOX_CODEEND;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		static const long ID_STATICBOX_FONTFILE;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_PANEL_PAINT;
		static const long ID_BUTTON_RUN;
		static const long ID_LISTBOX_COUNTRY;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		//*)

	private:
	    T100VOID            create();
	    T100VOID            destroy();

	    T100BOOL            verify();

	    T100BOOL            m_running       = T100FALSE;
	    T100FontTools       m_tools;
	    T100LONG            m_current       = -1;


		//(*Handlers(T100FontPanel)
		void OnFontChoiceSelect(wxCommandEvent& event);
		void OnFontSizeComboBoxSelected(wxCommandEvent& event);
		void OnFontSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnFontSizeComboBoxTextEnter(wxCommandEvent& event);
		void OnCountryListBoxSelect(wxCommandEvent& event);
		void OnFontCodeListCtrlItemSelect(wxListEvent& event);
		void OnCodeBeginComboBoxSelected(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeBeginComboBoxTextEnter(wxCommandEvent& event);
		void OnCodeEndComboBoxSelected(wxCommandEvent& event);
		void OnCodeEndComboBoxTextUpdated(wxCommandEvent& event);
		void OnCodeEndComboBoxTextEnter(wxCommandEvent& event);
		void OnAppendButtonClick(wxCommandEvent& event);
		void OnRemoveButtonClick(wxCommandEvent& event);
		void OnRunButtonClick(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnPaintPanelPaint(wxPaintEvent& event);
		void OnFontCodeListCtrlItemDeselect(wxListEvent& event);
		void OnNameCodeRadioButton1Select(wxCommandEvent& event);
		void OnNameCodeRadioButton2Select(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
