#ifndef T100VPCHOSTRUNDIALOG_H
#define T100VPCHOSTRUNDIALOG_H

#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>


class T100VPCHostRunDialog : public wxDialog
{
    public:
        T100VPCHostRunDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCHostRunDialog();

		wxComboBox*         ComboBoxBase;
		wxComboBox*         ComboBoxOffset;
		wxStaticText*       StaticText1;
		wxStaticText*       StaticText2;

    protected:
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_BASE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_OFFSET;


    private:
		void OnComboBoxBaseSelected(wxCommandEvent& event);
		void OnComboBoxBaseTextUpdated(wxCommandEvent& event);
		void OnComboBoxBaseTextEnter(wxCommandEvent& event);
		void OnComboBoxOffsetSelected(wxCommandEvent& event);
		void OnComboBoxOffsetTextUpdated(wxCommandEvent& event);
		void OnComboBoxOffsetTextEnter(wxCommandEvent& event);

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100VPCHOSTRUNDIALOG_H
