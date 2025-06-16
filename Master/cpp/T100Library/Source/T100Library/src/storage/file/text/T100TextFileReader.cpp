#include "storage/file/text/T100TextFileReader.h"

namespace T100LIBRARY{

T100TextFileReader::T100TextFileReader(const T100TextFile& file) :
    T100FileReader(),
    m_textFile(file)
{
    //ctor
    init();
}

T100TextFileReader::~T100TextFileReader()
{
    //dtor
    uninit();
}

T100VOID T100TextFileReader::init()
{
    T100STRING      filename;

    m_ifstream  = T100NEW std::ifstream(filename, std::ios::in);
}

T100VOID T100TextFileReader::uninit()
{
    if(m_ifstream){
        m_ifstream->close();
    }
    T100SAFE_DELETE(m_ifstream);
}

T100VOID T100TextFileReader::Seek(T100UINT value)
{
    m_ifstream->seekg(value);
}

T100VOID T100TextFileReader::Read()
{

}

}
