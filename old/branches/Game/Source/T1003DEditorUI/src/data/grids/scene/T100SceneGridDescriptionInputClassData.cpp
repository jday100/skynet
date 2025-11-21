#include "T100SceneGridDescriptionInputClassData.h"

#include "data/T100Scene.h"

T100SceneGridDescriptionInputClassData::T100SceneGridDescriptionInputClassData(wxPropertyGrid* grid, T100Scene* scene, T1003DEditorSceneGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_scenePtr(scene),
    m_sceneData(data),
    m_index(index)
{
    //ctor
}

T100SceneGridDescriptionInputClassData::~T100SceneGridDescriptionInputClassData()
{
    //dtor
}

T100VOID T100SceneGridDescriptionInputClassData::Update(wxPGProperty* property)
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
