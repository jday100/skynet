#include "T100EntityGridDescriptionsAmountData.h"

#include "entity/T100Entity.h"

T100EntityGridDescriptionsAmountData::T100EntityGridDescriptionsAmountData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data)
{
    //ctor
}

T100EntityGridDescriptionsAmountData::~T100EntityGridDescriptionsAmountData()
{
    //dtor
}

T100VOID T100EntityGridDescriptionsAmountData::Update(wxPGProperty* property)
{
    T100BOOL    value   = property->GetValue().GetBool();

    m_entityPtr->Shader.INHERIT     = value;


}
