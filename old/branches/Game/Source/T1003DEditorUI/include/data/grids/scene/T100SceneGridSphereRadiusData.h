#ifndef T100SCENEGRIDSPHERERADIUSDATA_H
#define T100SCENEGRIDSPHERERADIUSDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridSphereRadiusData : public T100GridClientData
{
    public:
        T100SceneGridSphereRadiusData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridSphereRadiusData();

        virtual T100VOID            Update(wxPGProperty*);

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:
};

#endif // T100SCENEGRIDSPHERERADIUSDATA_H
