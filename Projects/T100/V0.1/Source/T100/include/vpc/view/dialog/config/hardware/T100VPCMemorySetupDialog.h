#ifndef T100VPCMEMORYSETUPDIALOG_H
#define T100VPCMEMORYSETUPDIALOG_H

#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

#include "T100Common.h"

namespace T100VPC{
class T100MemoryInfo;

class T100VPCMemorySetupDialog : public wxDialog
{
    public:
        T100VPCMemorySetupDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
        virtual ~T100VPCMemorySetupDialog();

        wxStaticText*       StaticText1;
        wxStaticText*       StaticText2;
        wxStaticText*       StaticText3;
        wxStaticText*       StaticText4;

        wxComboBox*         RomBaseComboBox;
        wxComboBox*         RomSizeComboBox;
        wxComboBox*         RamBaseComboBox;
        wxComboBox*         RamSizeComboBox;

        T100VOID            setInfo(T100MemoryInfo*);

    protected:
        static const long ID_STATICTEXT_ROM_BASE;
        static const long ID_STATICTEXT_ROM_SIZE;
        static const long ID_STATICTEXT_RAM_BASE;
        static const long ID_STATICTEXT_RAM_SIZE;

        static const long ID_COMBOBOX_ROM_BASE;
        static const long ID_COMBOBOX_ROM_SIZE;
        static const long ID_COMBOBOX_RAM_BASE;
        static const long ID_COMBOBOX_RAM_SIZE;

    private:
        void OnRomBaseComboBoxSelected(wxCommandEvent& event);
        void OnRomBaseComboBoxTextUpdated(wxCommandEvent& event);
        void OnRomBaseComboBoxTextEnter(wxCommandEvent& event);
        void OnRomSizeComboBoxSelected(wxCommandEvent& event);
        void OnRomSizeComboBoxTextUpdated(wxCommandEvent& event);
        void OnRomSizeComboBoxTextEnter(wxCommandEvent& event);
        void OnRamBaseComboBoxSelected(wxCommandEvent& event);
        void OnRamBaseComboBoxTextUpdated(wxCommandEvent& event);
        void OnRamBaseComboBoxTextEnter(wxCommandEvent& event);
        void OnRamSizeComboBoxSelected(wxCommandEvent& event);
        void OnRamSizeComboBoxTextUpdated(wxCommandEvent& event);
        void OnRamSizeComboBoxTextEnter(wxCommandEvent& event);

    private:
        T100MemoryInfo*     m_info          = T100NULL;

        T100VOID            load();

        void BuildContent(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100VPCMEMORYSETUPDIALOG_H
