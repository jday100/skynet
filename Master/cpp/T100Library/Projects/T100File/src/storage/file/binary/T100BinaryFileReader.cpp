#include "storage/file/binary/T100BinaryFileReader.h"

#include "string/T100Unicode.h"
#include "storage/file/binary/T100BinaryFile.h"

namespace T100LIBRARY{

T100BinaryFileReader::T100BinaryFileReader(const T100BinaryFile& file) :
    T100FileReader(),
    m_binaryFile(file)
{
    //ctor
    init();
}

T100BinaryFileReader::~T100BinaryFileReader()
{
    //dtor
    uninit();
}

T100VOID T100BinaryFileReader::init()
{
    T100STRING          filename;

    filename    = T100Unicode::ToString8(m_binaryFile.GetEntryName());

    m_ifstream  = T100NEW std::ifstream(filename.c_str(), std::ios::in | std::ios::binary);

    if(m_ifstream){
        if(m_ifstream->is_open()){

        }else{
            T100SAFE_DELETE(m_ifstream);
        }
    }else{

    }
}

T100VOID T100BinaryFileReader::uninit()
{
    if(m_ifstream){
        m_ifstream->close();
        T100SAFE_DELETE(m_ifstream);
    }
}

T100VOID T100BinaryFileReader::Seek(T100UINT value)
{
    m_ifstream->seekg(value);
}

T100INT T100BinaryFileReader::Read(T100BYTE* data, T100INT length)
{
    T100INT         result;

    result  = m_ifstream->read(data, length).gcount();

    return result;
}

}
