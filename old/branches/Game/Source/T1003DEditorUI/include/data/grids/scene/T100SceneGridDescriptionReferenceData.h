#ifndef T100SCENEGRIDDESCRIPTIONREFERENCEDATA_H
#define T100SCENEGRIDDESCRIPTIONREFERENCEDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"
#include "T1003DEditorDescriptionFile.h"

class T100Scene;

class T100SceneGridDescriptionReferenceData : public T100GridClientData
{
    friend class T100SceneGridDescriptionsAmountData;
    public:
        T100SceneGridDescriptionReferenceData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&, T100UINT);
        virtual ~T100SceneGridDescriptionReferenceData();

        virtual T100VOID            Update(wxPGProperty*);

    protected:
        T100UINT                    m_index             = 0;
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

        T1003DEDITOR_GRID_DATA_DESCRIPTION*             m_descData      = T100NULL;
        T100D3D12_INPUT_ELEMENT_DESC*                   m_desc          = T100NULL;

        T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR*         m_descs         = T100NULL;

    private:
};

#endif // T100SCENEGRIDDESCRIPTIONREFERENCEDATA_H
