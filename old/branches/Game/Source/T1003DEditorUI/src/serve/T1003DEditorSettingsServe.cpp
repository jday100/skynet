#include "T1003DEditorSettingsServe.h"

T1003DEditorSettingsServe::T1003DEditorSettingsServe() :
    m_vertexDescriptions(),
    m_shaderParameters(),
    m_vertexShaders(),
    m_pixelShaders()
{
    //ctor
}

T1003DEditorSettingsServe::~T1003DEditorSettingsServe()
{
    //dtor
}

T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& T1003DEditorSettingsServe::GetVertexDescriptions()
{
    return m_vertexDescriptions;
}

T1003DEDITOR_SHADER_PARAMETER_VECTOR& T1003DEditorSettingsServe::GetShaderParameters()
{
    return m_shaderParameters;
}

T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& T1003DEditorSettingsServe::GetDescriptionReferences()
{
    return m_descriptionReferences;
}

T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR& T1003DEditorSettingsServe::GetParameterReferences()
{
    return m_parameterReferences;
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorSettingsServe::GetVertexShaders()
{
    return m_vertexShaders;
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorSettingsServe::GetPixelShaders()
{
    return m_pixelShaders;
}

T1003DEDITOR_SHADER_VECTOR& T1003DEditorSettingsServe::GetShaders()
{
    return m_shaders;
}

T100VOID T1003DEditorSettingsServe::GetDescriptions(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T100D3D12_INPUT_ELEMENT_DESC* desc : m_vertexDescriptions){
        labels.Add(desc->SemanticName);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetDescriptionReferences(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T1003DEditorDescriptionReferenceData* data : m_descriptionReferences){
        labels.Add(data->Name);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetParameters(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T100ShaderParameter* para : m_shaderParameters){
        labels.Add(para->Name);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetParameterReferences(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T1003DEditorParameterReferenceData* data : m_parameterReferences){
        labels.Add(data->Name);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetVertexShaders(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T100SHADER_FILE* shader : m_vertexShaders){
        labels.Add(shader->NAME);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetPixelShaders(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T100SHADER_FILE* shader : m_pixelShaders){
        labels.Add(shader->NAME);
        values.Add(index++);
    }
}

T100VOID T1003DEditorSettingsServe::GetShaders(wxArrayString& labels, wxArrayInt& values)
{
    T100UINT    index   = 0;
    labels.Add("");
    values.Add(-1);
    for(T1003DEditorShaderData* data : m_shaders){
        labels.Add(data->Name);
        values.Add(index++);
    }
}
