#ifndef T100SCENEGRIDTYPEDATA_H
#define T100SCENEGRIDTYPEDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridTypeData : public T100GridClientData
{
    public:
        T100SceneGridTypeData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridTypeData();

        virtual T100VOID            Update(wxPGProperty*);
        T100VOID                    CreateItems();

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

        T100VOID                    RemoveItems();

        T100DX12_SCENE_SPATIAL_TYPE             ConvertType(T100UINT);

    private:
};

#endif // T100SCENEGRIDTYPEDATA_H
