#ifndef T100SCENEGRIDSHADERREFERENCEDATA_H
#define T100SCENEGRIDSHADERREFERENCEDATA_H

#include "common/T100DX12Common.h"
#include "T100GridClientData.h"
#include "T1003DEditorSceneGridData.h"

class T100Scene;

class T100SceneGridShaderReferenceData : public T100GridClientData
{
    public:
        T100SceneGridShaderReferenceData(wxPropertyGrid*, T100Scene*, T1003DEditorSceneGridData&);
        virtual ~T100SceneGridShaderReferenceData();

        virtual T100VOID            Update(wxPGProperty*);

    protected:
        T100Scene*                  m_scenePtr          = T100NULL;
        T1003DEditorSceneGridData&  m_sceneData;

    private:

};

#endif // T100SCENEGRIDSHADERREFERENCEDATA_H
