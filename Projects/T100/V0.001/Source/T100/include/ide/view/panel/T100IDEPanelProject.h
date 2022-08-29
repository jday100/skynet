#ifndef T100IDEPANELPROJECT_H
#define T100IDEPANELPROJECT_H

//(*Headers(T100IDEPanelProject)
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/treectrl.h>
//*)

class T100IDEPanelProject: public wxPanel
{
	public:

		T100IDEPanelProject(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100IDEPanelProject();

		//(*Declarations(T100IDEPanelProject)
		wxTreeCtrl* TreeCtrl1;
		//*)

	protected:

		//(*Identifiers(T100IDEPanelProject)
		static const long ID_TREECTRL1;
		//*)

	private:

		//(*Handlers(T100IDEPanelProject)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
