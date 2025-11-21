#include "T100EntityGridParametersAmountData.h"

#include "entity/T100Entity.h"

T100EntityGridParametersAmountData::T100EntityGridParametersAmountData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data)
{
    //ctor
}

T100EntityGridParametersAmountData::~T100EntityGridParametersAmountData()
{
    //dtor
}

T100VOID T100EntityGridParametersAmountData::Update(wxPGProperty* property)
{
    T100UINT    value   = property->GetValue().GetInteger();

    m_entityPtr->ShaderParameters.Amount    = value;

    RemoveParameters();

    if(value){
        m_entityPtr->ShaderParameters.Parameters     = T100NEW T100ShaderParameter[value];
    }

    CreateParameters();

}

T100VOID T100EntityGridParametersAmountData::CreateParameters()
{
    T100UINT    value   = m_entityPtr->ShaderParameters.Amount;

    m_entityData.m_parameterProperties.resize(value);

    for(T100UINT i = 0; i < value; i++){
        CreateParameter(m_entityData.m_parameters, i);
    }
}

T100VOID T100EntityGridParametersAmountData::RemoveParameters()
{
    if(m_entityPtr->ShaderParameters.Amount){
        T100SAFE_DELETES m_entityPtr->ShaderParameters.Parameters;
        m_entityPtr->ShaderParameters.Parameters     = T100NULL;
    }

    for(T1003DEDITOR_GRID_DATA_PARAMETER& parameter : m_entityData.m_parameterProperties){
        m_gridPtr->DeleteProperty(parameter.RangeType);
        m_gridPtr->DeleteProperty(parameter.Length);
        m_gridPtr->DeleteProperty(parameter.Register);
        m_gridPtr->DeleteProperty(parameter.Space);
        m_gridPtr->DeleteProperty(parameter.Flags);
        m_gridPtr->DeleteProperty(parameter.Offset);
        m_gridPtr->DeleteProperty(parameter.NumRanges);
        m_gridPtr->DeleteProperty(parameter.Visibility);
    }
}

T100VOID T100EntityGridParametersAmountData::CreateParameter(wxPGProperty* parent, T100UINT index)
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    T1003DEDITOR_GRID_DATA_PARAMETER&   parameter       = m_entityData.m_parameterProperties[index];
    T100ShaderParameter&    item        = m_entityPtr->ShaderParameters.Parameters[index];

    wxString    label           = wxString::Format(L"Parameter%u", index + 1);

    parameter.Category          = T100NEW wxStringProperty(label);
    parameter.RangeType         = T100NEW wxEnumProperty(wxT("RangeType"), wxT("RangeType"), enumTypeLabels, enumTypeValues, item.RangeType);
    parameter.Length            = T100NEW wxUIntProperty(wxT("Length"), wxT("Length"), item.DescriptorsLength);
    parameter.Register          = T100NEW wxUIntProperty(wxT("Register"), wxT("Register"), item.BaseShaderRegister);
    parameter.Space             = T100NEW wxUIntProperty(wxT("Space"), wxT("Space"), item.RegisterSpace);
    parameter.Flags             = T100NEW wxEnumProperty(wxT("Flags"), wxT("Flags"), enumTypeLabels, enumTypeValues, item.Flags);

    parameter.NumRanges         = T100NEW wxUIntProperty(wxT("NumRanges"), wxT("NumRanges"), item.NumRanges);
    parameter.Visibility        = T100NEW wxEnumProperty(wxT("Visibility"), wxT("Visibility"), enumTypeLabels, enumTypeValues, item.Visibility);

    parameter.Category->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    parameter.Category->AppendChild(parameter.RangeType);
    parameter.Category->AppendChild(parameter.Length);
    parameter.Category->AppendChild(parameter.Register);
    parameter.Category->AppendChild(parameter.Space);
    parameter.Category->AppendChild(parameter.Flags);
    parameter.Category->AppendChild(parameter.NumRanges);
    parameter.Category->AppendChild(parameter.Visibility);

    parent->AppendChild(parameter.Category);
}
