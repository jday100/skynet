#ifndef T100DISKCREATEDIALOG_H
#define T100DISKCREATEDIALOG_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>


class T100DiskCreateDialog : public wxDialog
{
    public:
        T100DiskCreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskCreateDialog();


        wxButton*           BrowseButton;
		wxComboBox*         LengthComboBox;
		wxStaticText*       StaticText1;
		wxStaticText*       StaticText2;
		wxTextCtrl*         FileTextCtrl;


    protected:


    private:
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX1;

    private:
        void OnBrowseButtonClick(wxCommandEvent& event);

    protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKCREATEDIALOG_H
