#include "storage/file/text/T100TextFileAccessor.h"

namespace T100LIBRARY{

T100TextFileAccessor::T100TextFileAccessor(const T100TextFile& file) :
    T100FileAccessor(),
    m_textFile(file)
{
    //ctor
    init();
}

T100TextFileAccessor::~T100TextFileAccessor()
{
    //dtor
    uninit();
}

T100VOID T100TextFileAccessor::init()
{
    T100STRING      filename;

    m_fstream   = T100NEW std::fstream(filename, std::ios::in | std::ios::out);
}

T100VOID T100TextFileAccessor::uninit()
{
    if(m_fstream){
        m_fstream->close();
    }
    T100SAFE_DELETE(m_fstream);
}

T100VOID T100TextFileAccessor::SeekRead(T100UINT value)
{

}

T100VOID T100TextFileAccessor::Read()
{

}

T100VOID T100TextFileAccessor::SeekWrite(T100UINT value)
{

}

T100VOID T100TextFileAccessor::Write()
{

}

}
