#ifndef T100VPCCONFIGSETUPDEMODIALOG_H
#define T100VPCCONFIGSETUPDEMODIALOG_H

//(*Headers(T100VPCConfigSetupDemoDialog)
#include <wx/dialog.h>
//*)

class T100VPCConfigSetupDemoDialog: public wxDialog
{
	public:

		T100VPCConfigSetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCConfigSetupDemoDialog();

		//(*Declarations(T100VPCConfigSetupDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100VPCConfigSetupDemoDialog)
		//*)

	private:

		//(*Handlers(T100VPCConfigSetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
