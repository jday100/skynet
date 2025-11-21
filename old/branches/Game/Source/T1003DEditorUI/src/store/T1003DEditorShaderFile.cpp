#include "T1003DEditorShaderFile.h"

T1003DEditorShaderFile::T1003DEditorShaderFile(T1003DEDITOR_SHADER_VECTOR& shaders) :
    m_shaders(shaders)
{
    //ctor
}

T1003DEditorShaderFile::~T1003DEditorShaderFile()
{
    //dtor
}

T1003DEDITOR_SHADER_VECTOR& T1003DEditorShaderFile::GetShaders()
{
    return m_shaders;
}

T100VOID T1003DEditorShaderFile::encode()
{
    JSON        json;

    for(T1003DEditorShaderData* data : m_shaders){
        JSON        thisShader;
        EncodeShader(data, thisShader);
        json.push_back(thisShader);
    }

    m_json["shaders"]       = json;
}

T100VOID T1003DEditorShaderFile::EncodeShader(T1003DEditorShaderData* data, JSON& json)
{

}

T100VOID T1003DEditorShaderFile::decode()
{
    JSON&       shaders     = m_json["shaders"];

    for(JSON::iterator it = shaders.begin(); it != shaders.end(); ++it)
    {
        JSON&       thisShader  = it.value();
        DecodeShader(thisShader);
    }
}

T100VOID T1003DEditorShaderFile::DecodeShader(JSON& json)
{
    T1003DEditorShaderData*     data        = T100NEW T1003DEditorShaderData();

    data->Name      = json["name"].get<std::wstring>();

    m_shaders.push_back(data);
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorShaderFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorShaderFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
