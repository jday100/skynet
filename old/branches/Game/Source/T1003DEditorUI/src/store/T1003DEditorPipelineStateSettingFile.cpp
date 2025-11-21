#include "T1003DEditorPipelineStateSettingFile.h"

T1003DEditorPipelineStateSettingFile::T1003DEditorPipelineStateSettingFile()
{
    //ctor
}

T1003DEditorPipelineStateSettingFile::~T1003DEditorPipelineStateSettingFile()
{
    //dtor
}

T100VOID T1003DEditorPipelineStateSettingFile::encode()
{

}

T100VOID T1003DEditorPipelineStateSettingFile::decode()
{

}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorPipelineStateSettingFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorPipelineStateSettingFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
