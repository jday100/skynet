#ifndef T100VPCDISPLAYSETUPDIALOG_H
#define T100VPCDISPLAYSETUPDIALOG_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

#include "T100Common.h"

namespace T100VPC{
class T100DisplayInfo;

class T100VPCDisplaySetupDialog : public wxDialog
{
    public:
        T100VPCDisplaySetupDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCDisplaySetupDialog();

        wxStaticText*       StaticText1;
        wxStaticText*       StaticText2;
        wxStaticText*       StaticText3;

        wxComboBox*         ScreenWidthComboBox;
        wxComboBox*         ScreenHeightComboBox;
        wxComboBox*         FontFileComboBox;
        wxButton*           FileBrowseButton;

        T100VOID            setInfo(T100DisplayInfo*);

    protected:
        static const long ID_STATICTEXT_SCREEN_WIDTH;
        static const long ID_STATICTEXT_SCREEN_HEIGHT;
        static const long ID_STATICTEXT_FONT_FILE;

        static const long ID_COMBOBOX_SCREEN_WIDTH;
        static const long ID_COMBOBOX_SCREEN_HEIGHT;
        static const long ID_COMBOBOX_FONT_FILE;
        static const long ID_BUTTON_FILE_BROWSE;

    private:
        void OnScreenWidthComboBoxSelected(wxCommandEvent& event);
        void OnScreenWidthComboBoxTextUpdated(wxCommandEvent& event);
        void OnScreenWidthComboBoxTextEnter(wxCommandEvent& event);
        void OnScreenHeightComboBoxSelected(wxCommandEvent& event);
        void OnScreenHeightComboBoxTextUpdated(wxCommandEvent& event);
        void OnScreenHeightComboBoxTextEnter(wxCommandEvent& event);
        void OnFontFileComboBoxSelected(wxCommandEvent& event);
        void OnFontFileComboBoxTextUpdated(wxCommandEvent& event);
        void OnFontFileComboBoxTextEnter(wxCommandEvent& event);
        void OnFileBrowseButtonClick(wxCommandEvent& event);

    private:
        T100DisplayInfo*    m_info          = T100NULL;

        T100VOID            load();

        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCDISPLAYSETUPDIALOG_H
