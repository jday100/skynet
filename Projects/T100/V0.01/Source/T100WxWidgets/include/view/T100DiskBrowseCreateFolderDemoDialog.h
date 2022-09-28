#ifndef T100DISKBROWSECREATEFOLDERDEMODIALOG_H
#define T100DISKBROWSECREATEFOLDERDEMODIALOG_H

//(*Headers(T100DiskBrowseCreateFolderDemoDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class T100DiskBrowseCreateFolderDemoDialog: public wxDialog
{
	public:

		T100DiskBrowseCreateFolderDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskBrowseCreateFolderDemoDialog();

		//(*Declarations(T100DiskBrowseCreateFolderDemoDialog)
		wxStaticText* StaticText1;
		wxTextCtrl* FolderTextCtrl;
		//*)

	protected:

		//(*Identifiers(T100DiskBrowseCreateFolderDemoDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL_FOLDER;
		//*)

	private:

		//(*Handlers(T100DiskBrowseCreateFolderDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
