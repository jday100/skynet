#ifndef T100SCENEGRIDRECTANGLEXDATA_H
#define T100SCENEGRIDRECTANGLEXDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridRectangleXData : public T100GridClientData
{
    public:
        T100SceneGridRectangleXData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridRectangleXData();

        virtual T100VOID            Update(wxPGProperty*);

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:
};

#endif // T100SCENEGRIDRECTANGLEXDATA_H
