#ifndef T1003DEDITORLIGHTGRID_H
#define T1003DEDITORLIGHTGRID_H

#include "T1003DEditorGridBase.h"
#include <wx/propgrid/advprops.h>
#include "data/T100Light.h"

class T1003DEditorLightGrid : public T1003DEditorGridBase
{
    public:
        T1003DEditorLightGrid(wxPropertyGrid*);
        virtual ~T1003DEditorLightGrid();

        virtual T100VOID            Update(T100Light*);
        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:
        T100Light*                  m_lightPtr      = T100NULL;
        wxStringProperty*           m_name;
        wxEnumProperty*             m_type;

        wxFloatProperty*            m_directionX;
        wxFloatProperty*            m_directionY;
        wxFloatProperty*            m_directionZ;

        wxFloatProperty*            m_positionX;
        wxFloatProperty*            m_positionY;
        wxFloatProperty*            m_positionZ;

        T100_LIGHT_TYPE             ConvertType(T100UINT);

        T100VOID                    CreateType();

    private:
};

#endif // T1003DEDITORLIGHTGRID_H
