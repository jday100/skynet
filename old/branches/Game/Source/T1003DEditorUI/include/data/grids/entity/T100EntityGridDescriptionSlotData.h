#ifndef T100ENTITYGRIDDESCRIPTIONSLOTDATA_H
#define T100ENTITYGRIDDESCRIPTIONSLOTDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorEntityGridData.h"

class T100Entity;

class T100EntityGridDescriptionSlotData : public T100GridClientData
{
    public:
        T100EntityGridDescriptionSlotData(wxPropertyGrid*, T100Entity*, T1003DEditorEntityGridData&, T100UINT);
        virtual ~T100EntityGridDescriptionSlotData();

        virtual T100VOID                Update(wxPGProperty*);

    protected:
        T100UINT                        m_index             = 0;
        T100Entity*                     m_entityPtr         = T100NULL;
        T1003DEditorEntityGridData&     m_entityData;

    private:
};

#endif // T100ENTITYGRIDDESCRIPTIONSLOTDATA_H
