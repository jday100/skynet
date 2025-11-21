#include "T100SceneGridDescriptionSlotData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionSlotData::T100SceneGridDescriptionSlotData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionSlotData::~T100SceneGridDescriptionSlotData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionSlotData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();
    wxString    name    = property->GetValueAsString();

    switch(value){
    case 0:
        {

        }
        break;
    }

    //m_scenePtr->VertexDescriptions.Descs[m_index].SemanticName      = name.ToStdString().c_str();
}
