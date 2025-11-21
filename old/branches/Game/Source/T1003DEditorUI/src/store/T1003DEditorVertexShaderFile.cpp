#include "T1003DEditorVertexShaderFile.h"

T1003DEditorVertexShaderFile::T1003DEditorVertexShaderFile() :
    m_vertexShaders()
{
    //ctor
}

T1003DEditorVertexShaderFile::~T1003DEditorVertexShaderFile()
{
    //dtor
}

T1003DEDITOR_SHADER_FILE_VECTOR& T1003DEditorVertexShaderFile::GetVertexShaders()
{
    return m_vertexShaders;
}

T100VOID T1003DEditorVertexShaderFile::encode()
{
    JSON        json;

    for(T100SHADER_FILE* data : m_vertexShaders){
        JSON        thisShader;
        EncodeShader(data, thisShader);
        json.push_back(thisShader);
    }

    m_json["vertexshaders"]     = json;
}

T100VOID T1003DEditorVertexShaderFile::EncodeShader(T100SHADER_FILE* shader, JSON& json)
{
    json["name"]            = shader->NAME;
    json["type"]            = shader->TYPE;
    json["file"]            = shader->FILE;
    json["realpath"]        = shader->REALPATH;
    json["entry"]           = shader->ENTRY;
    json["target"]          = shader->TARGET;
}

T100VOID T1003DEditorVertexShaderFile::decode()
{
    JSON&       shaders     = m_json["vertexshaders"];

    for(JSON::iterator it = shaders.begin(); it != shaders.end(); ++it){
        JSON&       thisShader      = it.value();
        DecodeShader(thisShader);
    }
}

T100VOID T1003DEditorVertexShaderFile::DecodeShader(JSON& json)
{
    T100SHADER_FILE*            data        = T100NEW T100SHADER_FILE();

    data->NAME                  = json["name"].get<std::wstring>();
    data->TYPE                  = json["type"];
    data->FILE                  = json["file"].get<std::wstring>();
    data->REALPATH              = json["realpath"].get<std::wstring>();
    data->ENTRY                 = json["entry"].get<std::wstring>();
    data->TARGET                = json["target"].get<std::wstring>();

    m_vertexShaders.push_back(data);
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorVertexShaderFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorVertexShaderFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
