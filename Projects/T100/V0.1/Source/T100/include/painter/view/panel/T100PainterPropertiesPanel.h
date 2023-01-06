#ifndef T100PAINTERPROPERTIESPANEL_H
#define T100PAINTERPROPERTIESPANEL_H

#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "T100Common.h"
#include "T100ElementBase.h"

namespace T100Painter{

class T100PainterPropertiesPanel : public wxPanel
{
    public:
        T100PainterPropertiesPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~T100PainterPropertiesPanel();

        wxListView*             ListView;

        T100BOOL                setElement(T100ElementBase*);

    protected:
        static const long ID_LISTVIEW;

    private:
        T100ElementBase*        m_element           = T100NULL;

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERPROPERTIESPANEL_H
