#ifndef T100VPCDISKSETUPDIALOG_H
#define T100VPCDISKSETUPDIALOG_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

#include "T100Common.h"

namespace T100VPC{
class T100DiskInfo;

class T100VPCDiskSetupDialog : public wxDialog
{
    public:
        T100VPCDiskSetupDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCDiskSetupDialog();

        wxStaticText*       StaticText1;
        wxStaticText*       StaticText2;
        wxStaticText*       StaticText3;

        wxTextCtrl*         FileNameTextCtrl;
        wxButton*           FileBrowseButton;
        wxComboBox*         FilePathComboBox;
        wxComboBox*         FileLengthComboBox;

        T100VOID            setInfo(T100DiskInfo*);

    protected:
        static const long ID_STATICTEXT_FILE_NAME;
        static const long ID_STATICTEXT_FILE_PATH;
        static const long ID_STATICTEXT_FILE_LENGTH;

        static const long ID_TEXTCTRL_FILE_NAME;
        static const long ID_BUTTON_FILE_BROWSE;
        static const long ID_COMBOBOX_FILE_PATH;
        static const long ID_COMBOBOX_FILE_LENGTH;

    private:
        void OnFileNameTextCtrlText(wxCommandEvent& event);
        void OnFileNameTextCtrlTextEnter(wxCommandEvent& event);
        void OnFileBrowseButtonClick(wxCommandEvent& event);
        void OnFilePathComboBoxSelected(wxCommandEvent& event);
        void OnFilePathComboBoxTextUpdated(wxCommandEvent& event);
        void OnFilePathComboBoxTextEnter(wxCommandEvent& event);
        void OnFileLengthComboBoxSelected(wxCommandEvent& event);
        void OnFileLengthComboBoxTextUpdated(wxCommandEvent& event);
        void OnFileLengthComboBoxTextEnter(wxCommandEvent& event);

    private:
        T100DiskInfo*       m_info          = T100NULL;

        T100VOID            load();

        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCDISKSETUPDIALOG_H
