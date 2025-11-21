#include "T1003DEditorParameterFile.h"

T1003DEditorParameterFile::T1003DEditorParameterFile() :
    m_shaderParameters()
{
    //ctor
}

T1003DEditorParameterFile::~T1003DEditorParameterFile()
{
    //dtor
}

T1003DEDITOR_SHADER_PARAMETER_VECTOR& T1003DEditorParameterFile::GetShaderParameters()
{
    return m_shaderParameters;
}

T100VOID T1003DEditorParameterFile::encode()
{
    JSON        json;

    for(T100ShaderParameter* para : m_shaderParameters){
        JSON        thisPara;
        EncodeParameter(para, thisPara);
        json.push_back(thisPara);
    }

    m_json["parameters"]        = json;
}

T100VOID T1003DEditorParameterFile::EncodeParameter(T100ShaderParameter* para, JSON& json)
{
    json["type"]            = para->RangeType;
    json["length"]          = para->DescriptorsLength;
    json["register"]        = para->BaseShaderRegister;
    json["space"]           = para->RegisterSpace;
    json["flags"]           = para->Flags;
    json["offset"]          = para->OffsetInDescriptorsFromTableStart;
    json["ranges"]          = para->NumRanges;
    json["visibility"]      = para->Visibility;
}

T100VOID T1003DEditorParameterFile::decode()
{
    JSON&       paras       = m_json["parameters"];

    for(JSON::iterator it = paras.begin(); it != paras.end(); ++it){
        JSON&       thisPara    = it.value();
        DecodeParameter(thisPara);
    }
}

T100VOID T1003DEditorParameterFile::DecodeParameter(JSON& json)
{
    T100ShaderParameter*        data        = T100NEW T100ShaderParameter();

    data->RangeType             = json["type"];
    data->DescriptorsLength     = json["length"];
    data->BaseShaderRegister    = json["register"];
    data->RegisterSpace         = json["space"];
    data->Flags                 = json["flags"];
    data->OffsetInDescriptorsFromTableStart     = json["offset"];
    data->NumRanges             = json["ranges"];
    data->Visibility            = json["visibility"];

    m_shaderParameters.push_back(data);
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorParameterFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorParameterFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
