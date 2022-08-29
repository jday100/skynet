#ifndef T100DISKREMOVEPARTDEMODIALOG_H
#define T100DISKREMOVEPARTDEMODIALOG_H

//(*Headers(T100DiskRemovePartDemoDialog)
#include <wx/dialog.h>
//*)

class T100DiskRemovePartDemoDialog: public wxDialog
{
	public:

		T100DiskRemovePartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskRemovePartDemoDialog();

		//(*Declarations(T100DiskRemovePartDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100DiskRemovePartDemoDialog)
		//*)

	private:

		//(*Handlers(T100DiskRemovePartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
