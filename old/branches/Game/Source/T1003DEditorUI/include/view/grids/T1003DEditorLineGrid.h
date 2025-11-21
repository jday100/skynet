#ifndef T1003DEDITORLINEGRID_H
#define T1003DEDITORLINEGRID_H

#include "entity/T100Line.h"
#include "T1003DEditorEntityGrid.h"

class T1003DEditorLineGrid : public T1003DEditorEntityGrid
{
    public:
        T1003DEditorLineGrid(wxPropertyGrid*);
        virtual ~T1003DEditorLineGrid();

        virtual T100VOID            Update(T100Entity*);
        virtual T100VOID            OnPGChanged(wxPropertyGridEvent& event);

    protected:
        wxFloatProperty*            m_lengthPtr         = T100NULL;
        wxPropertyCategory*         m_terminusPtr       = T100NULL;
        wxFloatProperty*            m_terminusXPtr      = T100NULL;
        wxFloatProperty*            m_terminusYPtr      = T100NULL;
        wxFloatProperty*            m_terminusZPtr      = T100NULL;

    protected:


    private:
};

#endif // T1003DEDITORLINEGRID_H
