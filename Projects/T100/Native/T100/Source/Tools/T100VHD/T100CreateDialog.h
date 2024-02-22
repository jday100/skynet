#ifndef T100CREATEDIALOG_H
#define T100CREATEDIALOG_H

//(*Headers(T100CreateDialog)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "T100Common.h"
#include "T100VDISKCommon.h"
#include "T100VHDCommon.h"


class T100CreateDialog: public wxDialog
{
	public:

		T100CreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~T100CreateDialog();

		//(*Declarations(T100CreateDialog)
		wxButton* ButtonFileBrowse;
		wxComboBox* ComboBoxFileLength;
		wxRadioButton* RadioButtonFileStorageDynamic;
		wxRadioButton* RadioButtonFileStorageFixed;
		wxRadioButton* RadioButtonFileTypeVHD;
		wxRadioButton* RadioButtonFileTypeVHDX;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrlFileName;
		//*)

    private:
        T100STRING                          m_filename;
        T100INT64                           m_length                = 0LL;
        T100VDISK_TYPE                      m_type                  = T100VDISK_TYPE_NONE;
        T100VDISK_STORAGE_TYPE              m_storage               = T100VDISK_STORAGE_TYPE_NONE;

        void OnButtonApplyClick(wxCommandEvent& event);

	protected:
	    T100VOID            create();
	    T100VOID            destroy();

		//(*Identifiers(T100CreateDialog)
		static const long ID_STATICTEXT1;
		static const long ID_COMBOBOX_FILE_LENGTH;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL_FILE_NAME;
		static const long ID_BUTTON_BROWSE;
		static const long ID_RADIOBUTTON_FILE_TYPE_VHD;
		static const long ID_RADIOBUTTON_FILE_TYPE_VHDX;
		static const long ID_RADIOBUTTON_FILE_STORAGE_FIXED;
		static const long ID_RADIOBUTTON_FILE_STORAGE_DYNAMIC;
		//*)

	private:

		//(*Handlers(T100CreateDialog)
		void OnRadioButton1Select(wxCommandEvent& event);
		void OnButtonFileBrowseClick(wxCommandEvent& event);
		void OnRadioButtonFileTypeVHDSelect(wxCommandEvent& event);
		void OnRadioButtonFileTypeVHDXSelect(wxCommandEvent& event);
		void OnRadioButtonFileStorageFixedSelect(wxCommandEvent& event);
		void OnRadioButtonFileStorageDynamicSelect(wxCommandEvent& event);
		void OnComboBoxFileLengthSelected(wxCommandEvent& event);
		void OnComboBoxFileLengthTextUpdated(wxCommandEvent& event);
		void OnComboBoxFileLengthTextEnter(wxCommandEvent& event);
		void OnTextCtrlFileNameText(wxCommandEvent& event);
		void OnTextCtrlFileNameTextEnter(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
