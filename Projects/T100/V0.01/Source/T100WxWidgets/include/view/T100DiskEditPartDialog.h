#ifndef T100DISKEDITPARTDIALOG_H
#define T100DISKEDITPARTDIALOG_H

#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include "T100Common.h"


class T100DiskEditPartDialog : public wxDialog
{
    public:
        T100DiskEditPartDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskEditPartDialog();

        wxCheckBox*             BootCheckBox;
		wxComboBox*             LengthComboBox;
		wxComboBox*             LocationComboBox;
		wxComboBox*             TypeComboBox;
		wxStaticText*           StaticText1;
		wxStaticText*           StaticText2;
		wxStaticText*           StaticText3;
		wxStaticText*           StaticText4;
		wxTextCtrl*             NameTextCtrl;


    protected:
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_NAME;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_LOCATION;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_LENGTH;
		static const long ID_CHECKBOX_BOOT;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX_TYPE;


    private:
        T100VOID            create();
        T100VOID            destroy();

        void OnNameTextCtrlText(wxCommandEvent& event);
		void OnNameTextCtrlTextEnter(wxCommandEvent& event);
		void OnLocationComboBoxSelected(wxCommandEvent& event);
		void OnLocationComboBoxTextUpdated(wxCommandEvent& event);
		void OnLocationComboBoxTextEnter(wxCommandEvent& event);
		void OnLengthComboBoxSelected(wxCommandEvent& event);
		void OnLengthComboBoxTextUpdated(wxCommandEvent& event);
		void OnLengthComboBoxTextEnter(wxCommandEvent& event);
		void OnBootCheckBoxClick(wxCommandEvent& event);
		void OnTypeComboBoxSelected(wxCommandEvent& event);
		void OnTypeComboBoxTextUpdated(wxCommandEvent& event);
		void OnTypeComboBoxTextEnter(wxCommandEvent& event);


        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKEDITPARTDIALOG_H
