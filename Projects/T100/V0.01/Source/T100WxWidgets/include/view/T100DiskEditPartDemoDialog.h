#ifndef T100DISKEDITPARTDEMODIALOG_H
#define T100DISKEDITPARTDEMODIALOG_H

//(*Headers(T100DiskEditPartDemoDialog)
#include <wx/dialog.h>
//*)

class T100DiskEditPartDemoDialog: public wxDialog
{
	public:

		T100DiskEditPartDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskEditPartDemoDialog();

		//(*Declarations(T100DiskEditPartDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100DiskEditPartDemoDialog)
		//*)

	private:

		//(*Handlers(T100DiskEditPartDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
