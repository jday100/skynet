#ifndef T1003DEDITORSHADERFILE_H
#define T1003DEDITORSHADERFILE_H

#include <fstream>
#include "game/file/T100JSON.h"
#include "data/settings/T1003DEditorShaderData.h"

class T1003DEditorShaderFile
{
    public:
        T1003DEditorShaderFile(T1003DEDITOR_SHADER_VECTOR&);
        virtual ~T1003DEditorShaderFile();

        T1003DEDITOR_SHADER_VECTOR&         GetShaders();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorShaderFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorShaderFile&);

    protected:
        JSON                                m_json;

    private:
        T1003DEDITOR_SHADER_VECTOR&         m_shaders;

        T100VOID                            encode();
        T100VOID                            EncodeShader(T1003DEditorShaderData*, JSON&);

        T100VOID                            decode();
        T100VOID                            DecodeShader(JSON&);
};

#endif // T1003DEDITORSHADERFILE_H
