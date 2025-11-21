#include "T100SceneGridDescriptionsReferenceData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionsReferenceData::T100SceneGridDescriptionsReferenceData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data)
{
    //ctor
}

T100SceneGridDescriptionsReferenceData::~T100SceneGridDescriptionsReferenceData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionsReferenceData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

}
