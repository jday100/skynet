#ifndef T1003DEDITORSHADERDATA_H
#define T1003DEDITORSHADERDATA_H

#include <vector>
#include "common/T100EntityCommon.h"

#define     T1003DEDITOR_SHADER_FILE_VECTOR             std::vector<T100SHADER_FILE*>
#define     T1003DEDITOR_SHADER_VECTOR                  std::vector<T1003DEditorShaderData*>

class T1003DEditorShaderData
{
    public:
        T1003DEditorShaderData();
        virtual ~T1003DEditorShaderData();

        T100WSTRING                         Name;

        T100VertexDescriptions              VertexDescriptions;
        T100ShaderParameters                ShaderParameters;

        T100SHADER_FILE                     VertexShaderFile;
        T100SHADER_FILE                     PixelShaderFile;

    protected:

    private:
};

#endif // T1003DEDITORSHADERDATA_H
