#ifndef T100SOURCEIMPORTDIALOG_H
#define T100SOURCEIMPORTDIALOG_H

//(*Headers(T100SourceImportDialog)
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

#include "T100Common.h"

class T100SourceImportDialog: public wxDialog
{
	public:

		T100SourceImportDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100SourceImportDialog();

		//(*Declarations(T100SourceImportDialog)
		wxDirPickerCtrl* DirPickerCtrl1;
		wxDirPickerCtrl* DirPickerCtrl2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(T100SourceImportDialog)
		static const long ID_STATICTEXT1;
		static const long ID_DIRPICKERCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_DIRPICKERCTRL2;
		//*)

	private:
	    T100VOID            OnApply(wxCommandEvent&);

		//(*Handlers(T100SourceImportDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
