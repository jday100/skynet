#include "T100SceneGridDescriptionFormatData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionFormatData::T100SceneGridDescriptionFormatData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionFormatData::~T100SceneGridDescriptionFormatData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionFormatData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();
    wxString    name    = property->GetValueAsString();

    switch(value){
    case 0:
        {

        }
        break;
    }

    //m_scenePtr->VertexDescriptions.Descs[m_index].Format    = name.ToStdString().c_str();
}
