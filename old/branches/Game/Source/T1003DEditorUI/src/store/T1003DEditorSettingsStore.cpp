#include "T1003DEditorSettingsStore.h"

#include "T1003DEditorConfig.h"
#include "T1003DEditorConfigFile.h"
#include "T1003DEditorDescriptionReferenceFile.h"

T1003DEditorSettingsStore::T1003DEditorSettingsStore()
{
    //ctor
}

T1003DEditorSettingsStore::~T1003DEditorSettingsStore()
{
    //dtor
}

T100BOOL T1003DEditorSettingsStore::LoadConfigFile()
{
    std::ifstream                   ifs(T1003DEditorConfig::ConfigFile);
    T1003DEditorConfigFile          config;

    ifs >> config;
}

T100BOOL T1003DEditorSettingsStore::SaveConfigFile()
{
    std::ofstream                   ofs(T1003DEditorConfig::ConfigFile);
    T1003DEditorConfigFile          config;

    ofs << config;
}

T100BOOL T1003DEditorSettingsStore::LoadShaders(T1003DEDITOR_SHADER_VECTOR& value)
{
    std::ifstream                   ifs(T1003DEditorConfig::SettingsShaderFile);
    T1003DEditorShaderFile          shader(value);

    ifs >> shader;
}

T100BOOL T1003DEditorSettingsStore::SaveShaders(T1003DEDITOR_SHADER_VECTOR& value)
{
    std::ofstream                   ofs(T1003DEditorConfig::SettingsShaderFile);
    T1003DEditorShaderFile          file(value);

    ofs << file;
}

T100BOOL T1003DEditorSettingsStore::LoadDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& value)
{
    std::ifstream                   ifs(T1003DEditorConfig::SettingsDescriptionFile);
    T1003DEditorDescriptionFile     file(value);

    ifs >> file;
}

T100BOOL T1003DEditorSettingsStore::SaveDescriptions(T1003DEDITOR_VERTEX_DESCRIPTION_VECTOR& value)
{
    std::ofstream                   ofs(T1003DEditorConfig::SettingsDescriptionFile);
    T1003DEditorDescriptionFile     file(value);

    ofs << file;
}

T100BOOL T1003DEditorSettingsStore::LoadDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& value)
{
    std::ifstream                               ifs(T1003DEditorConfig::SettingsDescriptionReferenceFile);
    T1003DEditorDescriptionReferenceFile        file(value);

    ifs >> file;
}

T100BOOL T1003DEditorSettingsStore::SaveDescriptionReferences(T1003DEDITOR_DESCRIPTION_REFERENCE_DATA_VECTOR& value)
{
    std::ofstream                               ofs(T1003DEditorConfig::SettingsDescriptionReferenceFile);
    T1003DEditorDescriptionReferenceFile        file(value);

    ofs << file;
}

T100BOOL T1003DEditorSettingsStore::LoadParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR& value)
{
    T100STRING          name        = "./config/parameter.json";

    std::ifstream                   ifs(name);
    T1003DEditorParameterFile       file;

    ifs >> file;

    value   = file.GetShaderParameters();
}

T100BOOL T1003DEditorSettingsStore::SaveParameters(T1003DEDITOR_SHADER_PARAMETER_VECTOR& value)
{

}

T100BOOL T1003DEditorSettingsStore::LoadParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR& value)
{

}

T100BOOL T1003DEditorSettingsStore::SaveParameterReferences(T1003DEDITOR_PARAMETER_REFERENCE_DATA_VECTOR& value)
{

}

T100BOOL T1003DEditorSettingsStore::LoadVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{
    T100STRING          name        = "./config/vertexshader.json";

    std::ifstream                   ifs(name);
    T1003DEditorVertexShaderFile    file;

    ifs >> file;

    value   = file.GetVertexShaders();
}

T100BOOL T1003DEditorSettingsStore::SaveVertexShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{

}

T100BOOL T1003DEditorSettingsStore::LoadPixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{
    T100STRING          name        = "./config/pixelshader.json";

    std::ifstream                   ifs(name);
    T1003DEditorPixelShaderFile     file;

    ifs >> file;

    value   = file.GetPixelShaders();
}

T100BOOL T1003DEditorSettingsStore::SavePixelShaders(T1003DEDITOR_SHADER_FILE_VECTOR& value)
{

}
