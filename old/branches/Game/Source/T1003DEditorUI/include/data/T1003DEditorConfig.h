#ifndef T1003DEDITORCONFIG_H
#define T1003DEDITORCONFIG_H

#include "T100Common.h"
#include "common/T100DX12Common.h"

class T1003DEditorConfig
{
    public:
        T1003DEditorConfig();
        virtual ~T1003DEditorConfig();

        static T100DX12_COORDINATE_SYSTEM_TYPE      DefaultCoordinateSystemType;
        static T100DX12_PROJECTION_TYPE             DefaultProjectiveType;

        static T100FLOAT            Width;
        static T100FLOAT            Height;

        static T100STRING           ConfigFile;
        static T100STRING           SettingsShaderFile;
        static T100STRING           SettingsDescriptionFile;
        static T100STRING           SettingsDescriptionReferenceFile;
        static T100STRING           SettingsParameterFile;
        static T100STRING           SettingsParameterReferenceFile;
        static T100STRING           SettingsPipelineStateSettingFile;
        static T100STRING           SettingsVertexShaderFile;
        static T100STRING           SettingsPixelShaderFile;

    protected:

    private:
};

#endif // T1003DEDITORCONFIG_H
