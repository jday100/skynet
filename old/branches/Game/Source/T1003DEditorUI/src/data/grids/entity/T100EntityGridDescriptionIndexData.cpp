#include "T100EntityGridDescriptionIndexData.h"

#include "entity/T100Entity.h"

T100EntityGridDescriptionIndexData::T100EntityGridDescriptionIndexData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data),
    m_index(index)
{
    //ctor
}

T100EntityGridDescriptionIndexData::~T100EntityGridDescriptionIndexData()
{
    //dtor
}

T100VOID T100EntityGridDescriptionIndexData::Update(wxPGProperty* property)
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
