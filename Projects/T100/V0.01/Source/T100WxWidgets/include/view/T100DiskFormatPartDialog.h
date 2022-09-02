#ifndef T100DISKFORMATPARTDIALOG_H
#define T100DISKFORMATPARTDIALOG_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>


class T100DiskFormatPartDialog : public wxDialog
{
    public:
        T100DiskFormatPartDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100DiskFormatPartDialog();

        wxButton*           BrowseButton;
		wxComboBox*         FileComboBox;
		wxStaticText*       StaticText1;

    protected:
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON_BROWSE;


    private:
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnBrowseButtonClick(wxCommandEvent& event);

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif // T100DISKFORMATPARTDIALOG_H
