#ifndef T1003DEDITORVERTEXSHADERFILE_H
#define T1003DEDITORVERTEXSHADERFILE_H

#include <fstream>
#include "game/file/T100JSON.h"
#include "T1003DEditorShaderData.h"

class T1003DEditorVertexShaderFile
{
    public:
        T1003DEditorVertexShaderFile();
        virtual ~T1003DEditorVertexShaderFile();

        T1003DEDITOR_SHADER_FILE_VECTOR&            GetVertexShaders();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorVertexShaderFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorVertexShaderFile&);

    protected:
        JSON                                        m_json;

    private:
        T1003DEDITOR_SHADER_FILE_VECTOR             m_vertexShaders;

        T100VOID                                    encode();
        T100VOID                                    EncodeShader(T100SHADER_FILE*, JSON&);

        T100VOID                                    decode();
        T100VOID                                    DecodeShader(JSON&);
};

#endif // T1003DEDITORVERTEXSHADERFILE_H
