#ifndef T1003DEDITORGRIDBASE_H
#define T1003DEDITORGRIDBASE_H

#include <wx/propgrid/propgrid.h>
#include "T100Common.h"

class T1003DEditorGridBase
{
    public:
        T1003DEditorGridBase(wxPropertyGrid*);
        virtual ~T1003DEditorGridBase();

        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event) = 0;

    protected:
        wxPropertyGrid*             m_propertyGridPtr           = T100NULL;

    private:
};

#endif // T1003DEDITORGRIDBASE_H
