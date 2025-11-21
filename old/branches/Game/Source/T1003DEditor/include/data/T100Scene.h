#ifndef T100SCENE_H
#define T100SCENE_H

#include "common/T100DX12Common.h"
#include "common/T100EntityCommon.h"
#include "game/file/T100JSON.h"

class T100Scene
{
    public:
        T100Scene();
        virtual ~T100Scene();

        T100DX12_SCENE_SPATIAL_TYPE         Type        = T100DX12_SCENE_RECTANGLE;

        T100FLOAT                           Length      = 0;
        T100FLOAT                           Width       = 0;
        T100FLOAT                           Height      = 0;
        T100FLOAT                           Radius      = 0;

        T100VertexDescriptions              VertexDescriptions;
        T100ShaderParameters                ShaderParameters;

        T100SHADER_FILE                     VertexShaderFile;
        T100SHADER_FILE                     PixelShaderFile;

        virtual T100VOID                    ToJSON(JSON&);
        virtual T100VOID                    FromJSON(JSON&);

    protected:
        T100DX12_SCENE_SPATIAL_TYPE         ConvertSceneType(T100UINT);
        T100SHADER_FILE_TYPE                ConvertShaderFileType(T100UINT);

    private:
        T100VOID                            init();
        T100VOID                            uninit();
};

#endif // T100SCENE_H
