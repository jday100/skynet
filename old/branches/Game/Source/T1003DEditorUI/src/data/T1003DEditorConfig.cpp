#include "T1003DEditorConfig.h"

T100DX12_COORDINATE_SYSTEM_TYPE         T1003DEditorConfig::DefaultCoordinateSystemType         = T100DX12_COORDINATE_SYSTEM_LEFT_HAND;
T100DX12_PROJECTION_TYPE                T1003DEditorConfig::DefaultProjectiveType               = T100DX12_PERSPECTIVE_PROJECTION;

T100FLOAT       T1003DEditorConfig::Width                               = 100;
T100FLOAT       T1003DEditorConfig::Height                              = 100;

T100STRING      T1003DEditorConfig::ConfigFile                          = "./config/config.json";
T100STRING      T1003DEditorConfig::SettingsShaderFile                  = "./config/shader.json";
T100STRING      T1003DEditorConfig::SettingsDescriptionFile             = "./config/description.json";
T100STRING      T1003DEditorConfig::SettingsDescriptionReferenceFile    = "./config/descriptionreference.json";
T100STRING      T1003DEditorConfig::SettingsParameterFile               = "./config/parameter.json";
T100STRING      T1003DEditorConfig::SettingsParameterReferenceFile      = "./config/parameterreference.json";
T100STRING      T1003DEditorConfig::SettingsPipelineStateSettingFile    = "./config/setting.json";
T100STRING      T1003DEditorConfig::SettingsVertexShaderFile            = "./config/vertexshader.json";
T100STRING      T1003DEditorConfig::SettingsPixelShaderFile             = "./config/pixelshader.json";

T1003DEditorConfig::T1003DEditorConfig()
{
    //ctor
}

T1003DEditorConfig::~T1003DEditorConfig()
{
    //dtor
}
