#ifndef T100SCENEGRIDDESCRIPTIONSAMOUNTDATA_H
#define T100SCENEGRIDDESCRIPTIONSAMOUNTDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridDescriptionsAmountData : public T100GridClientData
{
    public:
        T100SceneGridDescriptionsAmountData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridDescriptionsAmountData();

        virtual T100VOID            Update(wxPGProperty*);

        T100VOID                    CreateDescriptions();

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:
        T100VOID                    RemoveDescriptions();
        T100VOID                    CreateDescription(wxArrayString&, wxArrayInt&, wxPGProperty*, T100UINT);
};

#endif // T100SCENEGRIDDESCRIPTIONSAMOUNTDATA_H
