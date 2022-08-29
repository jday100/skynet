#ifndef T100DISKBROWSEPARTDEMODIALOG_H
#define T100DISKBROWSEPARTDEMODIALOG_H

//(*Headers(T100DiskBrowsePartDemoDialog)
#include <wx/dialog.h>
#include <wx/dirctrl.h>
#include <wx/sizer.h>
//*)

class T100DiskBrowsePartDemoDialog: public wxDialog
{
	public:

		T100DiskBrowsePartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskBrowsePartDemoDialog();

		//(*Declarations(T100DiskBrowsePartDemoDialog)
		wxGenericDirCtrl* GenericDirCtrl1;
		wxGenericDirCtrl* GenericDirCtrl2;
		//*)

	protected:

		//(*Identifiers(T100DiskBrowsePartDemoDialog)
		static const long ID_GENERICDIRCTRL1;
		static const long ID_GENERICDIRCTRL2;
		//*)

	private:

		//(*Handlers(T100DiskBrowsePartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
