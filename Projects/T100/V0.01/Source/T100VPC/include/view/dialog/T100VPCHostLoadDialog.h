#ifndef T100VPCHOSTLOADDIALOG_H
#define T100VPCHOSTLOADDIALOG_H

#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>


class T100VPCHostLoadDialog : public wxDialog
{
    public:
        T100VPCHostLoadDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHostLoadDialog();

		wxButton*           ButtonBrowse;
		wxCheckBox*         CheckBoxRun;
		wxComboBox*         ComboBoxFile;
		wxComboBox*         ComboBoxLocation;
		wxStaticText*       StaticText1;
		wxStaticText*       StaticText2;

    protected:
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_LOCATION;
		static const long ID_CHECKBOX_RUN;

    private:
		void OnComboBoxFileSelected(wxCommandEvent& event);
		void OnComboBoxFileTextUpdated(wxCommandEvent& event);
		void OnComboBoxFileTextEnter(wxCommandEvent& event);
		void OnButtonBrowseClick(wxCommandEvent& event);
		void OnComboBoxLocationSelected(wxCommandEvent& event);
		void OnComboBoxLocationTextUpdated(wxCommandEvent& event);
		void OnComboBoxLocationTextEnter(wxCommandEvent& event);
		void OnCheckBoxRunClick(wxCommandEvent& event);


		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100VPCHOSTLOADDIALOG_H
