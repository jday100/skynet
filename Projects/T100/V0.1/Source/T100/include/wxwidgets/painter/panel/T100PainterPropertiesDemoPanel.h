#ifndef T100PAINTERPROPERTIESDEMOPANEL_H
#define T100PAINTERPROPERTIESDEMOPANEL_H

//(*Headers(T100PainterPropertiesDemoPanel)
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class T100PainterPropertiesDemoPanel: public wxPanel
{
	public:

		T100PainterPropertiesDemoPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterPropertiesDemoPanel();

		//(*Declarations(T100PainterPropertiesDemoPanel)
		wxListView* ListView1;
		//*)

	protected:

		//(*Identifiers(T100PainterPropertiesDemoPanel)
		static const long ID_LISTVIEW1;
		//*)

	private:

		//(*Handlers(T100PainterPropertiesDemoPanel)
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
