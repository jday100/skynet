#include "T100SceneGridParametersReferenceData.h"

#include "data/T100Scene.h"

T100SceneGridParametersReferenceData::T100SceneGridParametersReferenceData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridParametersReferenceData::~T100SceneGridParametersReferenceData()
{
    //dtor
}

T100VOID T100SceneGridParametersReferenceData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

}
