#include "T1003DEditorParameterReferenceFile.h"

T1003DEditorParameterReferenceFile::T1003DEditorParameterReferenceFile()
{
    //ctor
}

T1003DEditorParameterReferenceFile::~T1003DEditorParameterReferenceFile()
{
    //dtor
}

T100VOID T1003DEditorParameterReferenceFile::encode()
{

}

T100VOID T1003DEditorParameterReferenceFile::decode()
{

}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorParameterReferenceFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorParameterReferenceFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
