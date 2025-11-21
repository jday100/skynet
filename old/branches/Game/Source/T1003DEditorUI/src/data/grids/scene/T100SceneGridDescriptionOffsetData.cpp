#include "T100SceneGridDescriptionOffsetData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionOffsetData::T100SceneGridDescriptionOffsetData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionOffsetData::~T100SceneGridDescriptionOffsetData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionOffsetData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

    m_scenePtr->VertexDescriptions.Descs[m_index].AlignedByteOffset     = value;
}
