#include "T100SceneGridRectangleZData.h"

#include "data/T100Scene.h"

T100SceneGridRectangleZData::T100SceneGridRectangleZData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridRectangleZData::~T100SceneGridRectangleZData()
{
    //dtor
}

T100VOID T100SceneGridRectangleZData::Update(wxPGProperty* property)
{
    T100FLOAT   value   = property->GetValue().GetDouble();

    m_scenePtr->Length  = value;
}
