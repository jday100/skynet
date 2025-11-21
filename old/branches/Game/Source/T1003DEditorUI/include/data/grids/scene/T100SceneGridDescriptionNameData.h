#ifndef T100SCENEGRIDDESCRIPTIONNAMEDATA_H
#define T100SCENEGRIDDESCRIPTIONNAMEDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridDescriptionNameData : public T100GridClientData
{
    public:
        T100SceneGridDescriptionNameData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&, T100UINT);
        virtual ~T100SceneGridDescriptionNameData();

        virtual T100VOID            Update(wxPGProperty*);

    protected:
        T100UINT                    m_index             = 0;
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:
};

#endif // T100SCENEGRIDDESCRIPTIONNAMEDATA_H
