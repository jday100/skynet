#include "T100EntityGridDescriptionInputClassData.h"

#include "entity/T100Entity.h"

T100EntityGridDescriptionInputClassData::T100EntityGridDescriptionInputClassData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data),
    m_index(index)
{
    //ctor
}

T100EntityGridDescriptionInputClassData::~T100EntityGridDescriptionInputClassData()
{
    //dtor
}

T100VOID T100EntityGridDescriptionInputClassData::Update(wxPGProperty* property)
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
