#ifndef T100VPCDISKSETUPDIALOG_H
#define T100VPCDISKSETUPDIALOG_H

#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

namespace T100VPC{

class T100VPCDiskSetupDialog : public wxDialog
{
    public:
        T100VPCDiskSetupDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCDiskSetupDialog();

        wxStaticText*       FileNameStaticText;
        wxStaticText*       FilePathStaticText;
        wxStaticText*       FileLengthStaticText;

        wxTextCtrl*         FileNameTextCtrl;
        wxComboBox*         FilePathComboBox;
        wxComboBox*         FileLengthComboBox;

    protected:
        static const long ID_STATICTEXT_FILE_NAME;
        static const long ID_STATICTEXT_FILE_PATH;
        static const long ID_STATICTEXT_FILE_LENGTH;

        static const long ID_TEXTCTRL_FILE_NAME;
        static const long ID_COMBOBOX_FILE_PATH;
        static const long ID_COMBOBOX_FILE_LENGTH;

    private:
        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCDISKSETUPDIALOG_H
