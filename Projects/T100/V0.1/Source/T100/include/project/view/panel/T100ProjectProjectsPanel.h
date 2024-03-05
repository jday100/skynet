#ifndef T100PROJECTPROJECTSPANEL_H
#define T100PROJECTPROJECTSPANEL_H

//(*Headers(T100ProjectProjectsPanel)
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100ProjectProjectsPanel: public wxPanel
{
	public:

		T100ProjectProjectsPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100ProjectProjectsPanel();

		//(*Declarations(T100ProjectProjectsPanel)
		//*)

	protected:

		//(*Identifiers(T100ProjectProjectsPanel)
		//*)

	private:

		//(*Handlers(T100ProjectProjectsPanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
