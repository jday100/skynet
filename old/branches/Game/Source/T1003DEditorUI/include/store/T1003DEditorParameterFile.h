#ifndef T1003DEDITORPARAMETERFILE_H
#define T1003DEDITORPARAMETERFILE_H

#include <vector>
#include <fstream>
#include "game/file/T100JSON.h"
#include "common/T100EntityCommon.h"

#define     T1003DEDITOR_SHADER_PARAMETER_VECTOR            std::vector<T100ShaderParameter*>

class T1003DEditorParameterFile
{
    public:
        T1003DEditorParameterFile();
        virtual ~T1003DEditorParameterFile();

        T1003DEDITOR_SHADER_PARAMETER_VECTOR&       GetShaderParameters();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorParameterFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorParameterFile&);

    protected:
        JSON                                        m_json;

    private:
        T1003DEDITOR_SHADER_PARAMETER_VECTOR        m_shaderParameters;

        T100VOID                                    encode();
        T100VOID                                    EncodeParameter(T100ShaderParameter*, JSON&);

        T100VOID                                    decode();
        T100VOID                                    DecodeParameter(JSON&);
};

#endif // T1003DEDITORPARAMETERFILE_H
