#include "3d/T1003DFileReader.h"

#include "T100Unicode.h"

T1003DFileReader::T1003DFileReader(T100WSTRING filename, T1003DFILE_TYPE type) :
    m_filename(filename),
    m_type(type)
{
    //ctor
    init();
}

T1003DFileReader::~T1003DFileReader()
{
    //dtor
    uninit();
}

T100VOID T1003DFileReader::init()
{
    T100STRING      filename;

    filename    = T100Unicode::to_string8(m_filename);

    m_ifstream  = T100NEW std::ifstream(filename);
}

T100VOID T1003DFileReader::uninit()
{
    T100SAFE_DELETE m_ifstream;
}

std::ifstream& operator>>(T1003DFileReader& reader, JSON& json)
{
    *reader.m_ifstream >> json;
    return *reader.m_ifstream;
}

std::ifstream& operator>>(T1003DFileReader& reader, T1003DFile3DF& file)
{
    *reader.m_ifstream >> file.GetJSON();
    return *reader.m_ifstream;
}
