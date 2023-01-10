#ifndef T100ELEMENTMODULE_H
#define T100ELEMENTMODULE_H

#include <wx/propgrid/propgrid.h>
#include "T100ElementCommon.h"
#include "T100ElementBase.h"

namespace T100Painter{

class T100ElementModule : public T100ElementBase
{
    friend class T100ElementModuleSource;
    public:
        T100ElementModule();
        virtual ~T100ElementModule();

        T100VOID                Clear();
        T100BOOL                draw(wxDC&);
        T100ElementModule*      Clone();
        T100BOOL                Hit(T100INT, T100INT);

        T100BOOL                MouseLeftDown(T100INT, T100INT);
        T100BOOL                MouseLeftUp(T100INT, T100INT);
        T100BOOL                MouseMove(T100INT, T100INT);

        T100BOOL                Update(wxPropertyGrid*);
        T100BOOL                Update(wxPropertyGridEvent&);

        T100VOID                Resize(wxDC&);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        wxStringProperty*       m_pg_name       = T100NULL;
        wxIntProperty*          m_pg_x          = T100NULL;
        wxIntProperty*          m_pg_y          = T100NULL;

        T100ELEMENT_PROPERTY_HASH               m_properties;

};

}

#endif // T100ELEMENTMODULE_H
