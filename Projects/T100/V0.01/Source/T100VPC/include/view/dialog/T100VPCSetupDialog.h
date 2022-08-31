#ifndef T100VPCSETUPDIALOG_H
#define T100VPCSETUPDIALOG_H

#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/gbsizer.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include "T100Common.h"


class T100VPCSetupDialog : public wxDialog
{
    public:
        T100VPCSetupDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100VPCSetupDialog();

    protected:
		wxButton*           AppendButton;
		wxButton*           FileButton;
		wxButton*           FontFileButton;
		wxButton*           ROMFileButton;
		wxButton*           RemoveButton;
		wxButton*           VDiskFileButton;
		wxComboBox*         FileComboBox;
		wxComboBox*         FontFileComboBox;
		wxComboBox*         LengthComboBox;
		wxComboBox*         LocationComboBox;
		wxComboBox*         RAMBaseComboBox;
		wxComboBox*         RAMSizeComboBox;
		wxComboBox*         ROMBaseComboBox;
		wxComboBox*         ROMFileComboBox;
		wxComboBox*         ROMSizeComboBox;
		wxComboBox*         ScreenHeightComboBox;
		wxComboBox*         ScreenWidthComboBox;
		wxComboBox*         VDiskFileComboBox;
		wxListView*         FileListView;
		wxStaticText*       StaticText10;
		wxStaticText*       StaticText11;
		wxStaticText*       StaticText12;
		wxStaticText*       StaticText1;
		wxStaticText*       StaticText2;
		wxStaticText*       StaticText3;
		wxStaticText*       StaticText4;
		wxStaticText*       StaticText5;
		wxStaticText*       StaticText6;
		wxStaticText*       StaticText7;
		wxStaticText*       StaticText8;
		wxStaticText*       StaticText9;


    private:
        T100VOID            create();
        T100VOID            destroy();

        T100BOOL            load();
        T100BOOL            save();


		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FONT_FILE;
		static const long ID_BUTTON_FONT_FILE;
		static const long ID_STATICTEXT2;
		static const long ID_COMBOBOX_VDISK_FILE;
		static const long ID_BUTTON_VDISK_FILE;
		static const long ID_STATICTEXT3;
		static const long ID_COMBOBOX_ROM_BASE;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_COMBOBOX_ROM_SIZE;
		static const long ID_COMBOBOX_ROM_FILE;
		static const long ID_BUTTON_ROM_FILE;
		static const long ID_STATICTEXT6;
		static const long ID_COMBOBOX_RAM_BASE;
		static const long ID_STATICTEXT7;
		static const long ID_COMBOBOX_RAM_SIZE;
		static const long ID_LISTVIEW_FILE;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX_FILE;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT11;
		static const long ID_COMBOBOX_LOCATION;
		static const long ID_STATICTEXT12;
		static const long ID_COMBOBOX_LENGTH;
		static const long ID_BUTTON_APPEND;
		static const long ID_BUTTON_REMOVE;
		static const long ID_STATICTEXT8;
		static const long ID_COMBOBOX_SCREEN_WIDTH;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX_SCREEN_HEIGHT;


    protected:

		void OnFontFileComboBoxSelected(wxCommandEvent& event);
		void OnFontFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFontFileComboBoxTextEnter(wxCommandEvent& event);
		void OnFontFileButtonClick(wxCommandEvent& event);
		void OnVDiskFileComboBoxSelected(wxCommandEvent& event);
		void OnVDiskFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnVDiskFileComboBoxTextEnter(wxCommandEvent& event);
		void OnVDiskFileButtonClick(wxCommandEvent& event);
		void OnROMBaseComboBoxSelected(wxCommandEvent& event);
		void OnROMBaseComboBoxTextUpdated(wxCommandEvent& event);
		void OnROMBaseComboBoxTextEnter(wxCommandEvent& event);
		void OnROMSizeComboBoxSelected(wxCommandEvent& event);
		void OnROMSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnROMSizeComboBoxTextEnter(wxCommandEvent& event);
		void OnROMFileComboBoxSelected(wxCommandEvent& event);
		void OnROMFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnROMFileComboBoxTextEnter(wxCommandEvent& event);
		void OnROMFileButtonClick(wxCommandEvent& event);
		void OnRAMBaseComboBoxSelected(wxCommandEvent& event);
		void OnRAMBaseComboBoxTextUpdated(wxCommandEvent& event);
		void OnRAMBaseComboBoxTextEnter(wxCommandEvent& event);
		void OnRAMSizeComboBoxSelected(wxCommandEvent& event);
		void OnRAMSizeComboBoxTextUpdated(wxCommandEvent& event);
		void OnRAMSizeComboBoxTextEnter(wxCommandEvent& event);
		void OnFileListViewItemSelect(wxListEvent& event);
		void OnFileComboBoxSelected(wxCommandEvent& event);
		void OnFileComboBoxTextUpdated(wxCommandEvent& event);
		void OnFileComboBoxTextEnter(wxCommandEvent& event);
		void OnFileButtonClick(wxCommandEvent& event);
		void OnLocationComboBoxSelected(wxCommandEvent& event);
		void OnLocationComboBoxTextUpdated(wxCommandEvent& event);
		void OnLocationComboBoxTextEnter(wxCommandEvent& event);
		void OnLengthComboBoxSelected(wxCommandEvent& event);
		void OnLengthComboBoxTextUpdated(wxCommandEvent& event);
		void OnLengthComboBoxTextEnter(wxCommandEvent& event);
		void OnScreenWidthComboBoxSelected(wxCommandEvent& event);
		void OnScreenWidthComboBoxTextUpdated(wxCommandEvent& event);
		void OnScreenWidthComboBoxTextEnter(wxCommandEvent& event);
		void OnScreenHeightComboBoxSelected(wxCommandEvent& event);
		void OnScreenHeightComboBoxTextUpdated(wxCommandEvent& event);
		void OnScreenHeightComboBoxTextEnter(wxCommandEvent& event);


		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()

};

#endif // T100VPCSETUPDIALOG_H
