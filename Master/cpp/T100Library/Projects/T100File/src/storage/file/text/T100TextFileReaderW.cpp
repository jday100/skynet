#include "storage/file/text/T100TextFileReaderW.h"

#include "string/T100Unicode.h"
#include "storage/file/text/T100TextFile.h"

namespace T100LIBRARY{

T100TextFileReaderW::T100TextFileReaderW(const T100TextFile& file) :
    T100FileReader(),
    m_textFile(file)
{
    //ctor
    init();
}

T100TextFileReaderW::~T100TextFileReaderW()
{
    //dtor
    uninit();
}

T100VOID T100TextFileReaderW::init()
{
    T100STRING      filename;

    filename    = T100Unicode::ToString8(m_textFile.GetEntryName());

    m_wifstream = T100NEW std::wifstream(filename.c_str(), std::ios::in);

    if(m_wifstream){
        if(m_wifstream->is_open()){

        }else{
            T100SAFE_DELETE(m_wifstream);
        }
    }else{

    }
}

T100VOID T100TextFileReaderW::uninit()
{
    if(m_wifstream){
        m_wifstream->close();
        T100SAFE_DELETE(m_wifstream);
    }
}

T100VOID T100TextFileReaderW::Seek(T100UINT value)
{
    m_wifstream->seekg(value);
}

T100VOID T100TextFileReaderW::Load(T100WSTRING& value)
{
    T100WCHAR           buffer[1024];
    T100WSTRING         result;
    T100UINT            length;

    do{
        length  = m_wifstream->getline(buffer, 1024).gcount();
        if(length != 0){
            value += buffer;
            if(!m_wifstream->eof()){
                value += L"\r\n";
            }
        }
    }while(!m_wifstream->eof());
}

std::wifstream& T100TextFileReaderW::operator>>(T100WSTRING& value)
{
    *m_wifstream >> value;
    return *m_wifstream;
}

}
