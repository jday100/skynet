#include "storage/file/text/T100TextFileWriter.h"

#include "string/T100Unicode.h"
#include "storage/file/text/T100TextFile.h"

namespace T100LIBRARY{

T100TextFileWriter::T100TextFileWriter(const T100TextFile& file) :
    T100FileWriter(),
    m_textFile(file)
{
    //ctor
    init();
}

T100TextFileWriter::~T100TextFileWriter()
{
    //dtor
    uninit();
}

T100VOID T100TextFileWriter::init()
{
    T100STRING      filename;

    filename    = T100Unicode::ToString8(m_textFile.GetEntryName());

    m_ofstream  = T100NEW std::ofstream(filename, std::ios::out);
}

T100VOID T100TextFileWriter::uninit()
{
    if(m_ofstream){
        m_ofstream->close();
    }
    T100SAFE_DELETE(m_ofstream);
}

T100VOID T100TextFileWriter::Seek(T100UINT value)
{
    m_ofstream->seekp(value);
}

T100VOID T100TextFileWriter::Write()
{

}

}
