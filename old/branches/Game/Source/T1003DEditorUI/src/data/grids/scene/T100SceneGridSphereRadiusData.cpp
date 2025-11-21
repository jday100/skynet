#include "T100SceneGridSphereRadiusData.h"

#include "data/T100Scene.h"

T100SceneGridSphereRadiusData::T100SceneGridSphereRadiusData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridSphereRadiusData::~T100SceneGridSphereRadiusData()
{
    //dtor
}

T100VOID T100SceneGridSphereRadiusData::Update(wxPGProperty* property)
{
    T100FLOAT   value   = property->GetValue().GetDouble();

    m_scenePtr->Radius  = value;
}
