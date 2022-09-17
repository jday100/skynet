#ifndef T100DISKBROWSEPARTDEMODIALOG_H
#define T100DISKBROWSEPARTDEMODIALOG_H

//(*Headers(T100DiskBrowsePartDemoDialog)
#include <wx/dialog.h>
#include <wx/dirctrl.h>
#include <wx/menu.h>
#include <wx/sizer.h>
//*)
#include "T100FileSystemCtrl.h"


class T100DiskBrowsePartDemoDialog: public wxDialog
{
	public:

		T100DiskBrowsePartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskBrowsePartDemoDialog();

		//(*Declarations(T100DiskBrowsePartDemoDialog)
		wxGenericDirCtrl* GenericDirCtrl1;
		wxGenericDirCtrl* GenericDirCtrl2;
		wxMenu Menu1;
		wxMenu* MenuItem1;
		wxMenu* MenuItem4;
		wxMenuItem* MenuItem2;
		wxMenuItem* MenuItem3;
		wxMenuItem* MenuItem5;
		wxMenuItem* MenuItem6;
		//*)

	protected:

		//(*Identifiers(T100DiskBrowsePartDemoDialog)
		static const long ID_GENERICDIRCTRL1;
		static const long ID_GENERICDIRCTRL2;
		static const long ID_MENUITEM2;
		static const long ID_MENUITEM3;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM5;
		static const long ID_MENUITEM6;
		static const long ID_MENUITEM4;
		//*)

	private:

		//(*Handlers(T100DiskBrowsePartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
