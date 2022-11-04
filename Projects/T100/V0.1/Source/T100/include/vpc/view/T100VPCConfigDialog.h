#ifndef T100VPCCONFIGDIALOG_H
#define T100VPCCONFIGDIALOG_H

//(*Headers(T100VPCConfigDialog)
#include <wx/dialog.h>
//*)

namespace T100VPC{

class T100VPCConfigDialog: public wxDialog
{
	public:

		T100VPCConfigDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCConfigDialog();

		//(*Declarations(T100VPCConfigDialog)
		//*)

	protected:

		//(*Identifiers(T100VPCConfigDialog)
		//*)

	private:

		//(*Handlers(T100VPCConfigDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif
