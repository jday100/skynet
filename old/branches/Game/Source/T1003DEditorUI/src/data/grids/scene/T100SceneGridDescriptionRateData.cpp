#include "T100SceneGridDescriptionRateData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionRateData::T100SceneGridDescriptionRateData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionRateData::~T100SceneGridDescriptionRateData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionRateData::Update(wxPGProperty* property)
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
