#ifndef T100PAINTERPROPERTIESPANEL_H
#define T100PAINTERPROPERTIESPANEL_H

#include <wx/propgrid/propgrid.h>
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

        wxPropertyGrid*         PropertyGrid;

        T100BOOL                setElement(T100ElementBase*);

        T100VOID                Clear();

    protected:
        static const long ID_PROPERTYGRID;

        void OnChanged(wxPropertyGridEvent& event);

    private:
        T100ElementBase*        m_element           = T100NULL;

        void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

}

#endif // T100PAINTERPROPERTIESPANEL_H
