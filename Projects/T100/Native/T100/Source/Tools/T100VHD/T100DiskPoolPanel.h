#ifndef T100DISKPOOLPANEL_H
#define T100DISKPOOLPANEL_H

//(*Headers(T100DiskPoolPanel)
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100DiskPoolPanel: public wxPanel
{
	public:

		T100DiskPoolPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100DiskPoolPanel();

		//(*Declarations(T100DiskPoolPanel)
		wxPanel* Panel1;
		wxPanel* Panel2;
		wxPanel* Panel3;
		wxPanel* Panel4;
		//*)

	protected:

		//(*Identifiers(T100DiskPoolPanel)
		static const long ID_PANEL3;
		static const long ID_PANEL1;
		static const long ID_PANEL4;
		static const long ID_PANEL2;
		//*)

	private:

		//(*Handlers(T100DiskPoolPanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
