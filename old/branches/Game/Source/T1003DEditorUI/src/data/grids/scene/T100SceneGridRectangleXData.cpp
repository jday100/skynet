#include "T100SceneGridRectangleXData.h"

#include "data/T100Scene.h"

T100SceneGridRectangleXData::T100SceneGridRectangleXData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridRectangleXData::~T100SceneGridRectangleXData()
{
    //dtor
}

T100VOID T100SceneGridRectangleXData::Update(wxPGProperty* property)
{
    T100FLOAT   value   = property->GetValue().GetDouble();

    m_scenePtr->Width   = value;
}
