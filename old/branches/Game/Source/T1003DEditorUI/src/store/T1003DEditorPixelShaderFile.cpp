#include "T1003DEditorPixelShaderFile.h"

T1003DEditorPixelShaderFile::T1003DEditorPixelShaderFile() :
    m_pixelShaders()
{
    //ctor
}

T1003DEditorPixelShaderFile::~T1003DEditorPixelShaderFile()
{
    //dtor
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorPixelShaderFile::GetPixelShaders()
{
    return m_pixelShaders;
}

T100VOID T1003DEditorPixelShaderFile::encode()
{
    JSON        json;

    for(T100SHADER_FILE* data : m_pixelShaders){
        JSON        thisShader;
        EncodeShader(data, thisShader);
        json.push_back(thisShader);
    }

    m_json["pixelshaders"]      = json;
}

T100VOID T1003DEditorPixelShaderFile::EncodeShader(T100SHADER_FILE* shader, JSON& json)
{
    json["name"]            = std::wstring(shader->NAME);
    json["type"]            = shader->TYPE;
    json["file"]            = shader->FILE;
    json["realpath"]        = shader->REALPATH;
    json["entry"]           = shader->ENTRY;
    json["target"]          = shader->TARGET;
}

T100VOID T1003DEditorPixelShaderFile::decode()
{
    JSON&       shaders     = m_json["pixelshaders"];

    for(JSON::iterator it = shaders.begin(); it != shaders.end(); ++it){
        JSON&       thisShader      = it.value();
        DecodeShader(thisShader);
    }
}

T100VOID T1003DEditorPixelShaderFile::DecodeShader(JSON& json)
{
    T100SHADER_FILE*            data        = T100NEW T100SHADER_FILE();

    data->NAME                  = json["name"].get<std::wstring>();
    data->TYPE                  = json["type"];
    data->FILE                  = json["file"].get<std::wstring>();
    data->REALPATH              = json["realpath"].get<std::wstring>();
    data->ENTRY                 = json["entry"].get<std::wstring>();
    data->TARGET                = json["target"].get<std::wstring>();

    m_pixelShaders.push_back(data);
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorPixelShaderFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorPixelShaderFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
