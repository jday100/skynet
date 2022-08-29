#ifndef T100DISKCREATEPARTDIALOG_H
#define T100DISKCREATEPARTDIALOG_H

#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>



class T100DiskCreatePartDialog : public wxDialog
{
    public:
        T100DiskCreatePartDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskCreatePartDialog();

        wxCheckBox*             BootCheckBox;
		wxComboBox*             LengthComboBox;
		wxStaticText*           StaticText3;
		wxStaticText*           StaticText4;
		wxTextCtrl*             NameTextCtrl;

    private:
        static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX2;
		static const long ID_CHECKBOX2;

    protected:
        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKCREATEPARTDIALOG_H
