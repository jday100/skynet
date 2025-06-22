#include "storage/file/text/T100TextFileWriterW.h"

#include "string/T100Unicode.h"
#include "storage/file/text/T100TextFile.h"

namespace T100LIBRARY{

T100TextFileWriterW::T100TextFileWriterW(const T100TextFile& file) :
    T100FileWriter(),
    m_textFile(file)
{
    //ctor
    init();
}

T100TextFileWriterW::~T100TextFileWriterW()
{
    //dtor
    uninit();
}

T100VOID T100TextFileWriterW::init()
{
    T100STRING      filename;

    filename    = T100Unicode::ToString8(m_textFile.GetEntryName());

    m_wofstream = T100NEW std::wofstream(filename, std::ios::out);

    if(!m_wofstream->is_open()){
        m_wofstream->close();
        T100SAFE_DELETE(m_wofstream);
    }
}

T100VOID T100TextFileWriterW::uninit()
{
    if(m_wofstream)
    {
        m_wofstream->close();
    }
    T100SAFE_DELETE(m_wofstream);
}

T100VOID T100TextFileWriterW::Seek(T100UINT value)
{
    m_wofstream->seekp(value);
}

std::wofstream& T100TextFileWriterW::operator<<(const T100WSTRING& value)
{
    *m_wofstream << value;

    return *m_wofstream;
}

}
