#ifndef T100PAINTERPROPERTIESPANEL_H
#define T100PAINTERPROPERTIESPANEL_H

//(*Headers(T100PainterPropertiesPanel)
#include <wx/panel.h>
//*)

#include "T100ElementBase.h"

class T100PainterPropertiesPanel: public wxPanel
{
	public:

		T100PainterPropertiesPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~T100PainterPropertiesPanel();

		//(*Declarations(T100PainterPropertiesPanel)
		//*)

		T100VOID                    setElement(T100ElementBase*);

	protected:

		//(*Identifiers(T100PainterPropertiesPanel)
		//*)

	private:

		//(*Handlers(T100PainterPropertiesPanel)
		//*)

	protected:
	    T100ElementBase*            m_element           = T100NULL;

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
