#ifndef T100ENTITYGRIDDESCRIPTIONSREFERENCEDATA_H
#define T100ENTITYGRIDDESCRIPTIONSREFERENCEDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorEntityGridData.h"

class T100Entity;

class T100EntityGridDescriptionsReferenceData : public T100GridClientData
{
    public:
        T100EntityGridDescriptionsReferenceData(wxPropertyGrid*, T100Entity*, T1003DEditorEntityGridData&);
        virtual ~T100EntityGridDescriptionsReferenceData();

        virtual T100VOID                Update(wxPGProperty*);

    protected:
        T100UINT                        m_index             = 0;
        T100Entity*                     m_entityPtr         = T100NULL;
        T1003DEditorEntityGridData&     m_entityData;

    private:
};

#endif // T100ENTITYGRIDDESCRIPTIONSREFERENCEDATA_H
