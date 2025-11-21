#include "T1003DEditorConfigFile.h"

#include "T1003DEditorConfig.h"

T1003DEditorConfigFile::T1003DEditorConfigFile()
{
    //ctor
}

T1003DEditorConfigFile::~T1003DEditorConfigFile()
{
    //dtor
}

T100VOID T1003DEditorConfigFile::encode()
{
    m_json["coordinate"]        = T1003DEditorConfig::DefaultCoordinateSystemType;
    m_json["projection"]        = T1003DEditorConfig::DefaultProjectiveType;
}

T100VOID T1003DEditorConfigFile::decode()
{
    T1003DEditorConfig::DefaultCoordinateSystemType     = m_json["coordinate"];
    T1003DEditorConfig::DefaultProjectiveType           = m_json["projection"];
}

std::ifstream& operator>>(std::ifstream& ifs, T1003DEditorConfigFile& file)
{
    ifs >> file.m_json;
    file.decode();
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, T1003DEditorConfigFile& file)
{
    file.encode();
    ofs << file.m_json;
    return ofs;
}
