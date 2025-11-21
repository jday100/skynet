#ifndef T100ENTITYGRIDPARAMETERSAMOUNTDATA_H
#define T100ENTITYGRIDPARAMETERSAMOUNTDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorEntityGridData.h"

class T100Entity;

class T100EntityGridParametersAmountData : public T100GridClientData
{
    public:
        T100EntityGridParametersAmountData(wxPropertyGrid*, T100Entity*, T1003DEditorEntityGridData&);
        virtual ~T100EntityGridParametersAmountData();

        virtual T100VOID                Update(wxPGProperty*);

        T100VOID                        CreateParameters();

    protected:
        T100Entity*                     m_entityPtr         = T100NULL;
        T1003DEditorEntityGridData&     m_entityData;

    private:
        T100VOID                        RemoveParameters();
        T100VOID                        CreateParameter(wxPGProperty*, T100UINT);
};

#endif // T100ENTITYGRIDPARAMETERSAMOUNTDATA_H
