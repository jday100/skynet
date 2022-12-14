#ifndef T100VPCMEMORYSETUPDEMODIALOG_H
#define T100VPCMEMORYSETUPDEMODIALOG_H

//(*Headers(T100VPCMemorySetupDemoDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
//*)

class T100VPCMemorySetupDemoDialog: public wxDialog
{
	public:

		T100VPCMemorySetupDemoDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100VPCMemorySetupDemoDialog();

		//(*Declarations(T100VPCMemorySetupDemoDialog)
		//*)

	protected:

		//(*Identifiers(T100VPCMemorySetupDemoDialog)
		//*)

	private:

		//(*Handlers(T100VPCMemorySetupDemoDialog)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
