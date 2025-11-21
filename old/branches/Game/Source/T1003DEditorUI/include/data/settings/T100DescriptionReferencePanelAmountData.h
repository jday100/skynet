#ifndef T100DESCRIPTIONREFERENCEPANELAMOUNTDATA_H
#define T100DESCRIPTIONREFERENCEPANELAMOUNTDATA_H

#include "common/T100DX12Common.h"
#include "T1003DEditorGridDataBase.h"
#include "T100GridClientData.h"
#include "T1003DEditorDescriptionReferenceData.h"

class T100DescriptionReferencePanelAmountData : public T100GridClientData
{
    public:
        T100DescriptionReferencePanelAmountData(wxPropertyGrid*, T1003DEditorDescriptionReferenceData*, T100UINT);
        virtual ~T100DescriptionReferencePanelAmountData();

        virtual T100VOID                Update(wxPGProperty*);

    protected:
        T1003DEDITOR_GRID_DATA_DESCRIPTION_VECTOR   m_descriptionProperties;
        T1003DEditorDescriptionReferenceData*       m_desc;
        T100UINT                                    m_index         = 0;

    private:
        T100VOID                        CreateDescriptions();
        T100VOID                        RemoveDescriptions();
};

#endif // T100DESCRIPTIONREFERENCEPANELAMOUNTDATA_H
