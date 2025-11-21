#include "T100EntityGridShaderInheritData.h"

#include "entity/T100Entity.h"
#include "T100EntityGridAllDatas.h"

T100EntityGridShaderInheritData::T100EntityGridShaderInheritData(wxPropertyGrid* grid, T100Entity* entity, T1003DEditorEntityGridData& data) :
    T100GridClientData(grid),
    m_entityPtr(entity),
    m_entityData(data)
{
    //ctor
}

T100EntityGridShaderInheritData::~T100EntityGridShaderInheritData()
{
    //dtor
}

T100VOID T100EntityGridShaderInheritData::Update(wxPGProperty* property)
{
    T100BOOL    value   = property->GetValue().GetBool();

    m_entityPtr->Shader.INHERIT     = value;

    if(value){
        RemoveShader();
    }else{
        BuildShader();
    }
}

T100VOID T100EntityGridShaderInheritData::CreateShader()
{
    T100BOOL    value   = m_entityPtr->Shader.INHERIT;

    if(value){

    }else{
        BuildShader();
    }
}

T100VOID T100EntityGridShaderInheritData::BuildShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT(""),
        wxT(""),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };


    m_entityData.m_shaderReference      = T100NEW wxEnumProperty(wxT("Reference"), wxT("shaderreference"), enumTypeLabels, enumTypeValues);
    m_entityData.m_shader->AppendChild(m_entityData.m_shaderReference);

    CreateDescriptions();
    CreateParameters();
    CreateSettings();
    CreateVertexShader();
    CreatePixelShader();
}

T100VOID T100EntityGridShaderInheritData::RemoveShader()
{
    m_gridPtr->DeleteProperty(m_entityData.m_shaderReference);
}

T100VOID T100EntityGridShaderInheritData::CreateDescriptions()
{
    static const wxChar* enumTypeLabels[] = {
        wxT(""),
        wxT(""),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };

    T100UINT    value   = m_entityPtr->VertexDescriptions.Amount;

    m_entityData.m_descriptions  = T100NEW wxStringProperty(wxT("Descriptions"));
    m_entityData.m_descriptions->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_entityData.m_shader->AppendChild(m_entityData.m_descriptions);

    m_entityData.m_descriptionsReference     = T100NEW wxEnumProperty(wxT("Reference"), wxT("descriptionsreference"), enumTypeLabels, enumTypeValues);
    T100EntityGridDescriptionsReferenceData*     referenceData       = T100NEW T100EntityGridDescriptionsReferenceData(m_gridPtr, m_entityPtr, m_entityData);
    m_entityData.m_descriptionsReference->SetClientObject(referenceData);
    m_entityData.m_descriptions->AppendChild(m_entityData.m_descriptionsReference);

    m_entityData.m_descriptionsAmount        = T100NEW wxUIntProperty(wxT("Amount"), wxT("descriptionsamount"), m_entityPtr->VertexDescriptions.Amount);
    T100EntityGridDescriptionsAmountData*        amountData          = T100NEW T100EntityGridDescriptionsAmountData(m_gridPtr, m_entityPtr, m_entityData);
    m_entityData.m_descriptionsAmount->SetClientObject(amountData);
    m_entityData.m_descriptions->AppendChild(m_entityData.m_descriptionsAmount);

    m_entityData.m_descriptionProperties.resize(value);

    for(T100UINT i = 0; i < value; i++){
        CreateDescription(m_entityData.m_descriptions, i);
    }
}

T100VOID T100EntityGridShaderInheritData::CreateDescription(wxPGProperty* parent, T100UINT index)
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    T1003DEDITOR_GRID_DATA_DESCRIPTION&     description     = m_entityData.m_descriptionProperties[index];
    T100D3D12_INPUT_ELEMENT_DESC&           desc            = m_entityPtr->VertexDescriptions.Descs[index];

    wxString    label           = wxString::Format(L"Description%u", index + 1);
    description.Category        = T100NEW wxStringProperty(label);
    description.Name            = T100NEW wxStringProperty(wxT("Name"), wxT("name"), desc.SemanticName);
    description.Index           = T100NEW wxUIntProperty(wxT("Index"), wxT("Index"), desc.SemanticIndex);
    description.Format          = T100NEW wxEnumProperty(wxT("Format"), wxT("Format"), enumTypeLabels, enumTypeValues, desc.Format);
    description.Slot            = T100NEW wxUIntProperty(wxT("Slot"), wxT("Slot"), desc.InputSlot);
    description.InputClass      = T100NEW wxEnumProperty(wxT("InputClass"), wxT("InputClass"), enumTypeLabels, enumTypeValues, desc.InputSlotClass);
    description.Rate            = T100NEW wxUIntProperty(wxT("Rate"), wxT("Rate"), desc.InstanceDataStepRate);

    description.Category->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    description.Category->AppendChild(description.Name);
    description.Category->AppendChild(description.Index);
    description.Category->AppendChild(description.Format);
    description.Category->AppendChild(description.Slot);
    description.Category->AppendChild(description.InputClass);
    description.Category->AppendChild(description.Rate);

    T100EntityGridDescriptionNameData*          nameData            = T100NEW T100EntityGridDescriptionNameData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.Name->SetClientObject(nameData);
    T100EntityGridDescriptionIndexData*         indexData           = T100NEW T100EntityGridDescriptionIndexData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.Index->SetClientObject(indexData);
    T100EntityGridDescriptionFormatData*        formatData          = T100NEW T100EntityGridDescriptionFormatData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.Format->SetClientObject(formatData);
    T100EntityGridDescriptionSlotData*          slotData            = T100NEW T100EntityGridDescriptionSlotData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.Slot->SetClientObject(slotData);
    T100EntityGridDescriptionInputClassData*    inputClassData      = T100NEW T100EntityGridDescriptionInputClassData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.InputClass->SetClientObject(inputClassData);
    T100EntityGridDescriptionRateData*          rateData            = T100NEW T100EntityGridDescriptionRateData(m_gridPtr, m_entityPtr, m_entityData, index);
    description.Rate->SetClientObject(rateData);

    parent->AppendChild(description.Category);
}

T100VOID T100EntityGridShaderInheritData::CreateParameters()
{
    static const wxChar* enumTypeLabels[] = {
        wxT(""),
        wxT(""),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };

    m_entityData.m_parameters    = T100NEW wxStringProperty(wxT("Parameters"));
    m_entityData.m_parameters->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_entityData.m_shader->AppendChild(m_entityData.m_parameters);

    m_entityData.m_parametersReference   = T100NEW wxEnumProperty(wxT("Reference"), wxT("parametersreference"), enumTypeLabels, enumTypeValues);

    m_entityData.m_parameters->AppendChild(m_entityData.m_parametersReference);


    m_entityData.m_parametersAmount      = T100NEW wxUIntProperty(wxT("Amount"), wxT("parametersamount"), m_entityPtr->ShaderParameters.Amount);
    T100EntityGridParametersAmountData*  amountData      = T100NEW T100EntityGridParametersAmountData(m_gridPtr, m_entityPtr, m_entityData);
    m_entityData.m_parametersAmount->SetClientObject(amountData);
    m_entityData.m_parameters->AppendChild(m_entityData.m_parametersAmount);

    amountData->CreateParameters();

}

T100VOID T100EntityGridShaderInheritData::CreateSettings()
{
    static const wxChar* enumTypeLabels[] = {
        wxT(""),
        wxT(""),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };

    m_entityData.m_settings      = T100NEW wxStringProperty(wxT("Settings"));
    m_entityData.m_settings->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_entityData.m_shader->AppendChild(m_entityData.m_settings);

    m_entityData.m_settingsReference     = T100NEW wxEnumProperty(wxT("Reference"), wxT("settingsreference"), enumTypeLabels, enumTypeValues);
    m_entityData.m_settings->AppendChild(m_entityData.m_settingsReference);
}

T100VOID T100EntityGridShaderInheritData::CreateVertexShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    m_entityData.m_vertexCategory        = T100NEW wxStringProperty(wxT("VertexShader"));
    m_entityData.m_vertexCategory->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_entityData.m_shader->AppendChild(m_entityData.m_vertexCategory);

    m_entityData.m_vertexShader.Type     = T100NEW wxEnumProperty(wxT("FileType"), wxT("vertexshaderfiletype"), enumTypeLabels, enumTypeValues, m_entityPtr->VertexShaderFile.TYPE);
    m_entityData.m_vertexCategory->AppendChild(m_entityData.m_vertexShader.Type);

    m_entityData.m_vertexShader.File     = T100NEW wxFileProperty(wxT("FileName"), wxT("vertexshaderfilename"), m_entityPtr->VertexShaderFile.FILE);
    m_entityData.m_vertexCategory->AppendChild(m_entityData.m_vertexShader.File);

    switch(m_entityPtr->VertexShaderFile.TYPE){
    case T100DX12_SHADER_FILE_SOURCE:
        {
            m_entityData.m_vertexShader.Entry        = T100NEW wxStringProperty(wxT("Entry"), wxT("vertexshaderentry"), m_entityPtr->VertexShaderFile.ENTRY);
            m_entityData.m_vertexShader.Target       = T100NEW wxStringProperty(wxT("Target"), wxT("vertexshadertarget"), m_entityPtr->VertexShaderFile.TARGET);

            m_entityData.m_vertexCategory->AppendChild(m_entityData.m_vertexShader.Entry);
            m_entityData.m_vertexCategory->AppendChild(m_entityData.m_vertexShader.Target);
        }
        break;
    }
}

T100VOID T100EntityGridShaderInheritData::CreatePixelShader()
{

    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    m_entityData.m_pixelCategory         = T100NEW wxStringProperty(wxT("PixelShader"));
    m_entityData.m_pixelCategory->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_entityData.m_shader->AppendChild(m_entityData.m_pixelCategory);

    m_entityData.m_pixelShader.Type      = T100NEW wxEnumProperty(wxT("FileType"), wxT("pixelshaderfiletype"), enumTypeLabels, enumTypeValues, m_entityPtr->PixelShaderFile.TYPE);
    m_entityData.m_pixelCategory->AppendChild(m_entityData.m_pixelShader.Type);

    m_entityData.m_pixelShader.File      = T100NEW wxFileProperty(wxT("FileName"), wxT("pixelshaderfilename"), m_entityPtr->PixelShaderFile.FILE);
    m_entityData.m_pixelCategory->AppendChild(m_entityData.m_pixelShader.File);

    switch(m_entityPtr->PixelShaderFile.TYPE){
    case T100DX12_SHADER_FILE_SOURCE:
        {
            m_entityData.m_pixelShader.Entry         = T100NEW wxStringProperty(wxT("Entry"), wxT("pixelshaderentry"), m_entityPtr->PixelShaderFile.ENTRY);
            m_entityData.m_pixelShader.Target        = T100NEW wxStringProperty(wxT("Target"), wxT("pixelshadertarget"), m_entityPtr->PixelShaderFile.TARGET);

            m_entityData.m_pixelCategory->AppendChild(m_entityData.m_pixelShader.Entry);
            m_entityData.m_pixelCategory->AppendChild(m_entityData.m_pixelShader.Target);
        }
        break;
    }
}
