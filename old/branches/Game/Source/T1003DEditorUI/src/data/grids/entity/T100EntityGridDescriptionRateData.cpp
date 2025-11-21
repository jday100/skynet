#include "T100EntityGridDescriptionRateData.h"

#include "entity/T100Entity.h"

T100EntityGridDescriptionRateData::T100EntityGridDescriptionRateData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data, T100UINT index) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data),
    m_index(index)
{
    //ctor
}

T100EntityGridDescriptionRateData::~T100EntityGridDescriptionRateData()
{
    //dtor
}

T100VOID T100EntityGridDescriptionRateData::Update(wxPGProperty* property)
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
