#ifndef T100PSVMCREATEDIALOG_H
#define T100PSVMCREATEDIALOG_H

//(*Headers(T100PSVMCreateDialog)
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#include "T100Common.h"

class T100PSVMCreateDialog: public wxDialog
{
	public:

		T100PSVMCreateDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PSVMCreateDialog();

		//(*Declarations(T100PSVMCreateDialog)
		wxFilePickerCtrl* FilePickerCtrlFirmware;
		wxStaticText* StaticText1;
		//*)

		T100STRING          GetValue();

	protected:

		//(*Identifiers(T100PSVMCreateDialog)
		static const long ID_STATICTEXT1;
		static const long ID_FILEPICKERCTRL1;
		//*)

	private:

		//(*Handlers(T100PSVMCreateDialog)
		void OnFilePickerCtrlFirmwareFileChanged(wxFileDirPickerEvent& event);
		//*)

		void OnApply(wxCommandEvent&);

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
