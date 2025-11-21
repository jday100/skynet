#include "T100SceneGridRectangleYData.h"

#include "data/T100Scene.h"

T100SceneGridRectangleYData::T100SceneGridRectangleYData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridRectangleYData::~T100SceneGridRectangleYData()
{
    //dtor
}

T100VOID T100SceneGridRectangleYData::Update(wxPGProperty* property)
{
    T100FLOAT   value   = property->GetValue().GetDouble();

    m_scenePtr->Height  = value;
}
