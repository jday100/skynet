#include "T1003DEditorSceneGrid.h"

#include "T1003DEditorCallback.h"
#include "T100SceneGridAllDatas.h"

T1003DEditorSceneGrid::T1003DEditorSceneGrid(wxPropertyGrid* grid) :
    T1003DEditorGridBase(grid)
{
    //ctor
}

T1003DEditorSceneGrid::~T1003DEditorSceneGrid()
{
    //dtor
}

T100VOID T1003DEditorSceneGrid::Update(T100Scene* scene)
{
    m_scenePtr  = scene;

    m_propertyGridPtr->Clear();

    CreateType();
    CreateShader();
}

T100VOID T1003DEditorSceneGrid::OnPGChanged(wxPropertyGridEvent& event)
{
    wxPGProperty*           property    = event.GetProperty();

    if(property){
        T100GridClientData*     data    = dynamic_cast<T100GridClientData*>(property->GetClientObject());
        if(data){
            data->Update(property);
            T1003DEditorCallback::SetDirty();
        }
    }

}

T100VOID T1003DEditorSceneGrid::CreateType()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Rectangle"),
        wxT("Sphere"),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };

    m_sceneData.m_typePtr       = T100NEW wxEnumProperty(wxT("Type"), wxT("type"), enumTypeLabels, enumTypeValues, m_scenePtr->Type);
    T100SceneGridTypeData*  typeData    = T100NEW T100SceneGridTypeData(m_propertyGridPtr, m_scenePtr, m_sceneData);
    m_sceneData.m_typePtr->SetClientObject(typeData);
    m_propertyGridPtr->Append(m_sceneData.m_typePtr);

    wxString    name;

    switch(m_scenePtr->Type){
    case 0:
        {
            name    = L"Rectangle";
        }
        break;
    case 1:
        {
            name    = L"Sphere";
        }
        break;
    }

    m_sceneData.m_typeCategory  = T100NEW wxPropertyCategory(name, wxT("typecategory"));
    m_propertyGridPtr->Append(m_sceneData.m_typeCategory);

    typeData->CreateItems();
}

T100VOID T1003DEditorSceneGrid::CreateShader()
{
    wxArrayString   labels;
    wxArrayInt      values;

    T1003DEditorCallback::GetShaders(labels, values);

    m_sceneData.m_shader    = T100NEW wxPropertyCategory(wxT("Shader"));
    m_propertyGridPtr->Append(m_sceneData.m_shader);

    m_sceneData.m_shaderReference   = T100NEW wxEnumProperty(wxT("Reference"), wxT("reference"), labels, values);
    T100SceneGridShaderReferenceData*       data    = T100NEW T100SceneGridShaderReferenceData(m_propertyGridPtr, m_scenePtr, m_sceneData);
    m_sceneData.m_shaderReference->SetClientObject(data);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_shaderReference);

    CreateDescriptions();
    CreateParameters();
    CreateSettings();
    CreateVertexShader();
    CreatePixelShader();
}

T100VOID T1003DEditorSceneGrid::CreateDescriptions()
{
    wxArrayString   labels;
    wxArrayInt      values;

    T1003DEditorCallback::GetDescriptionReferences(labels, values);

    m_sceneData.m_descriptions  = T100NEW wxStringProperty(wxT("Descriptions"));
    m_sceneData.m_descriptions->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_descriptions);

    m_sceneData.m_descriptionsReference     = T100NEW wxEnumProperty(wxT("Reference"), wxT("descriptionsreference"), labels, values);
    T100SceneGridDescriptionsReferenceData*     referenceData       = T100NEW T100SceneGridDescriptionsReferenceData(m_propertyGridPtr, m_scenePtr, m_sceneData);
    m_sceneData.m_descriptionsReference->SetClientObject(referenceData);
    m_sceneData.m_descriptions->AppendChild(m_sceneData.m_descriptionsReference);

    m_sceneData.m_descriptionsAmount        = T100NEW wxUIntProperty(wxT("Amount"), wxT("descriptionsamount"), m_scenePtr->VertexDescriptions.Amount);
    T100SceneGridDescriptionsAmountData*        amountData          = T100NEW T100SceneGridDescriptionsAmountData(m_propertyGridPtr, m_scenePtr, m_sceneData);
    m_sceneData.m_descriptionsAmount->SetClientObject(amountData);
    m_sceneData.m_descriptions->AppendChild(m_sceneData.m_descriptionsAmount);

    amountData->CreateDescriptions();
}

T100VOID T1003DEditorSceneGrid::CreateParameters()
{
    wxArrayString   labels;
    wxArrayInt      values;

    T1003DEditorCallback::GetParameterReferences(labels, values);

    m_sceneData.m_parameters    = T100NEW wxStringProperty(wxT("Parameters"));
    m_sceneData.m_parameters->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_parameters);

    m_sceneData.m_parametersReference   = T100NEW wxEnumProperty(wxT("Reference"), wxT("parametersreference"), labels, values);

    m_sceneData.m_parameters->AppendChild(m_sceneData.m_parametersReference);


    m_sceneData.m_parametersAmount      = T100NEW wxUIntProperty(wxT("Amount"), wxT("parametersamount"), m_scenePtr->ShaderParameters.Amount);
    T100SceneGridParametersAmountData*  amountData      = T100NEW T100SceneGridParametersAmountData(m_propertyGridPtr, m_scenePtr, m_sceneData);
    m_sceneData.m_parametersAmount->SetClientObject(amountData);
    m_sceneData.m_parameters->AppendChild(m_sceneData.m_parametersAmount);

    amountData->CreateParameters();
}

T100VOID T1003DEditorSceneGrid::CreateSettings()
{
    static const wxChar* enumTypeLabels[] = {
        wxT(""),
        wxT(""),
        T100NULL
    };

    static long enumTypeValues[] = {
        0, 1
    };

    m_sceneData.m_settings      = T100NEW wxStringProperty(wxT("Settings"));
    m_sceneData.m_settings->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_settings);

    m_sceneData.m_settingsReference     = T100NEW wxEnumProperty(wxT("Reference"), wxT("settingsreference"), enumTypeLabels, enumTypeValues);
    m_sceneData.m_settings->AppendChild(m_sceneData.m_settingsReference);
}

T100VOID T1003DEditorSceneGrid::CreateVertexShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    wxArrayString   labels;
    wxArrayInt      values;

    T1003DEditorCallback::GetVertexShaders(labels, values);

    m_sceneData.m_vertexCategory        = T100NEW wxStringProperty(wxT("VertexShader"));
    m_sceneData.m_vertexShader.Reference    = T100NEW wxEnumProperty(wxT("Reference"), wxT("reference"), labels, values);
    m_sceneData.m_vertexShader.Type         = T100NEW wxEnumProperty(wxT("FileType"), wxT("vertexshaderfiletype"), enumTypeLabels, enumTypeValues, m_scenePtr->VertexShaderFile.TYPE);
    m_sceneData.m_vertexShader.File         = T100NEW wxFileProperty(wxT("FileName"), wxT("vertexshaderfilename"), m_scenePtr->VertexShaderFile.FILE);

    m_sceneData.m_vertexCategory->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_vertexCategory);

    m_sceneData.m_vertexCategory->AppendChild(m_sceneData.m_vertexShader.Reference);
    m_sceneData.m_vertexCategory->AppendChild(m_sceneData.m_vertexShader.Type);
    m_sceneData.m_vertexCategory->AppendChild(m_sceneData.m_vertexShader.File);

    switch(m_scenePtr->VertexShaderFile.TYPE){
    case T100DX12_SHADER_FILE_SOURCE:
        {
            m_sceneData.m_vertexShader.Entry        = T100NEW wxStringProperty(wxT("Entry"), wxT("vertexshaderentry"), m_scenePtr->VertexShaderFile.ENTRY);
            m_sceneData.m_vertexShader.Target       = T100NEW wxStringProperty(wxT("Target"), wxT("vertexshadertarget"), m_scenePtr->VertexShaderFile.TARGET);

            m_sceneData.m_vertexCategory->AppendChild(m_sceneData.m_vertexShader.Entry);
            m_sceneData.m_vertexCategory->AppendChild(m_sceneData.m_vertexShader.Target);
        }
        break;
    }
}

T100VOID T1003DEditorSceneGrid::CreatePixelShader()
{
    static const wxChar* enumTypeLabels[] = {
        wxT("Source"),
        wxT("Compiled"),
        T100NULL
    };

    static long enumTypeValues[] = {
        1, 2
    };

    wxArrayString   labels;
    wxArrayInt      values;

    T1003DEditorCallback::GetPixelShaders(labels, values);

    m_sceneData.m_pixelCategory             = T100NEW wxStringProperty(wxT("PixelShader"));
    m_sceneData.m_pixelShader.Reference     = T100NEW wxEnumProperty(wxT("Reference"), wxT("Reference"), labels, values, m_scenePtr->PixelShaderFile.TYPE);
    m_sceneData.m_pixelShader.Type          = T100NEW wxEnumProperty(wxT("FileType"), wxT("pixelshaderfiletype"), enumTypeLabels, enumTypeValues, m_scenePtr->PixelShaderFile.TYPE);
    m_sceneData.m_pixelShader.File          = T100NEW wxFileProperty(wxT("FileName"), wxT("pixelshaderfilename"), m_scenePtr->PixelShaderFile.FILE);

    m_sceneData.m_pixelCategory->ChangeFlag(wxPG_PROP_READONLY, T100TRUE);
    m_sceneData.m_shader->AppendChild(m_sceneData.m_pixelCategory);

    m_sceneData.m_pixelCategory->AppendChild(m_sceneData.m_pixelShader.Reference);
    m_sceneData.m_pixelCategory->AppendChild(m_sceneData.m_pixelShader.Type);
    m_sceneData.m_pixelCategory->AppendChild(m_sceneData.m_pixelShader.File);

    switch(m_scenePtr->PixelShaderFile.TYPE){
    case T100DX12_SHADER_FILE_SOURCE:
        {
            m_sceneData.m_pixelShader.Entry         = T100NEW wxStringProperty(wxT("Entry"), wxT("pixelshaderentry"), m_scenePtr->PixelShaderFile.ENTRY);
            m_sceneData.m_pixelShader.Target        = T100NEW wxStringProperty(wxT("Target"), wxT("pixelshadertarget"), m_scenePtr->PixelShaderFile.TARGET);

            m_sceneData.m_pixelCategory->AppendChild(m_sceneData.m_pixelShader.Entry);
            m_sceneData.m_pixelCategory->AppendChild(m_sceneData.m_pixelShader.Target);
        }
        break;
    }
}
