#include "T1003DFileWriter.h"

#include "T100Unicode.h"

T1003DFileWriter::T1003DFileWriter(T100WSTRING filename, T1003DFILE_TYPE type) :
    m_filename(filename),
    m_type(type)
{
    //ctor
    init();
}

T1003DFileWriter::~T1003DFileWriter()
{
    //dtor
    uninit();
}

T100VOID T1003DFileWriter::init()
{
    T100STRING      filename;

    filename    = T100Unicode::to_string8(m_filename);

    m_ofstream  = T100NEW std::ofstream(filename);
}

T100VOID T1003DFileWriter::uninit()
{
    T100SAFE_DELETE m_ofstream;
}

std::ofstream& operator<<(T1003DFileWriter& writer, const T100JSON& json)
{
    *writer.m_ofstream << json;
    return *writer.m_ofstream;
}

std::ofstream& operator<<(T1003DFileWriter& writer, T100File3DF& file)
{
    *writer.m_ofstream << file.GetJSON();
    return *writer.m_ofstream;
}
