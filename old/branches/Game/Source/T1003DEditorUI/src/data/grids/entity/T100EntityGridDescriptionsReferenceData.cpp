#include "T100EntityGridDescriptionsReferenceData.h"

#include "entity/T100Entity.h"

T100EntityGridDescriptionsReferenceData::T100EntityGridDescriptionsReferenceData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data)
{
    //ctor
}

T100EntityGridDescriptionsReferenceData::~T100EntityGridDescriptionsReferenceData()
{
    //dtor
}

T100VOID T100EntityGridDescriptionsReferenceData::Update(wxPGProperty* property)
{
    T100BOOL    value   = property->GetValue().GetBool();

    m_entityPtr->Shader.INHERIT     = value;


}
