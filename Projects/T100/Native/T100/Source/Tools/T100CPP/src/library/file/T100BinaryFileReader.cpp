#include "T100BinaryFileReader.h"

T100BinaryFileReader::T100BinaryFileReader(T100File& file)
    :T100FileReader()
{
    //ctor
    create(file);
}

T100BinaryFileReader::~T100BinaryFileReader()
{
    //dtor
}

T100VOID T100BinaryFileReader::create(T100File& file)
{
    m_stream    = T100NEW std::ifstream(file.m_name.ToStdChars(), std::ios::in | std::ios::binary);
}

T100VOID T100BinaryFileReader::destroy()
{

}

T100BOOL T100BinaryFileReader::open()
{

}

T100BOOL T100BinaryFileReader::close()
{

}

T100BOOL T100BinaryFileReader::read(T100BYTE* data, T100INTEGER& length)
{
    if(m_stream){
        m_stream->read((char*)data, length);
    }
    return T100FALSE;
}
