#include "T100SceneGridShaderReferenceData.h"

#include "data/T100Scene.h"

T100SceneGridShaderReferenceData::T100SceneGridShaderReferenceData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridShaderReferenceData::~T100SceneGridShaderReferenceData()
{
    //dtor
}

T100VOID T100SceneGridShaderReferenceData::Update(wxPGProperty* property)
{
    T100UINT        value       = property->GetValue().GetInteger();

    switch(value){
    case 0:
        {

        }
        break;
    default:
        {

        }
    }
}
