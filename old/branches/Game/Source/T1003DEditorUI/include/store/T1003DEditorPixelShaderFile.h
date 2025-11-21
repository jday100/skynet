#ifndef T1003DEDITORPIXELSHADERFILE_H
#define T1003DEDITORPIXELSHADERFILE_H

#include <fstream>
#include "game/file/T100JSON.h"
#include "T1003DEditorShaderData.h"

class T1003DEditorPixelShaderFile
{
    public:
        T1003DEditorPixelShaderFile();
        virtual ~T1003DEditorPixelShaderFile();

        T1003DEDITOR_SHADER_FILE_VECTOR&            GetPixelShaders();

        friend std::ifstream& operator>>(std::ifstream&, T1003DEditorPixelShaderFile&);
        friend std::ofstream& operator<<(std::ofstream&, T1003DEditorPixelShaderFile&);

    protected:
        JSON                                        m_json;

    private:
        T1003DEDITOR_SHADER_FILE_VECTOR             m_pixelShaders;

        T100VOID                                    encode();
        T100VOID                                    EncodeShader(T100SHADER_FILE*, JSON&);

        T100VOID                                    decode();
        T100VOID                                    DecodeShader(JSON&);
};

#endif // T1003DEDITORPIXELSHADERFILE_H
