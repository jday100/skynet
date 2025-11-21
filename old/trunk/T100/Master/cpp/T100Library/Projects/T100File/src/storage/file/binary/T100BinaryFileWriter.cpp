#include "storage/file/binary/T100BinaryFileWriter.h"

#include "string/T100Unicode.h"
#include "storage/file/binary/T100BinaryFile.h"

namespace T100LIBRARY{

T100BinaryFileWriter::T100BinaryFileWriter(const T100BinaryFile& file) :
    T100FileWriter(),
    m_binaryFile(file)
{
    //ctor
    init();
}

T100BinaryFileWriter::~T100BinaryFileWriter()
{
    //dtor
    uninit();
}

T100VOID T100BinaryFileWriter::init()
{
    T100STRING          filename;

    filename    = T100Unicode::ToString8(m_binaryFile.GetEntryName());

    m_ofstream  = T100NEW std::ofstream(filename.c_str(), std::ios::out | std::ios::binary);

    if(m_ofstream){
        if(m_ofstream->is_open()){

        }else{
            T100SAFE_DELETE(m_ofstream);
        }
    }else{

    }
}

T100VOID T100BinaryFileWriter::uninit()
{
    if(m_ofstream){
        m_ofstream->close();
        T100SAFE_DELETE(m_ofstream);
    }
}

T100VOID T100BinaryFileWriter::Seek(T100UINT value)
{
    m_ofstream->seekp(value);
}

T100VOID T100BinaryFileWriter::Write(T100BYTE* data, T100UINT length)
{
    m_ofstream->write(data, length);
}

}
