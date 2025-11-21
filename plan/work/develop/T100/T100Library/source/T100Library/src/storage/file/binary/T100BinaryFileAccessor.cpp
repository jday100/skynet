#include "storage/file/binary/T100BinaryFileAccessor.h"

#include "string/T100Unicode.h"
#include "storage/file/binary/T100BinaryFile.h"

namespace T100LIBRARY{

T100BinaryFileAccessor::T100BinaryFileAccessor(const T100BinaryFile& file) :
    T100FileAccessor(),
    m_binaryFile(file)
{
    //ctor
    init();
}

T100BinaryFileAccessor::~T100BinaryFileAccessor()
{
    //dtor
    uninit();
}

T100VOID T100BinaryFileAccessor::init()
{
    T100STRING      filename;

    filename    = T100Unicode::ToString8(m_binaryFile.GetEntryName());

    m_fstream   = T100NEW std::fstream(filename.c_str(), std::ios::in | std::ios::out | std::ios::binary);

    if(m_fstream){
        if(m_fstream->is_open()){

        }else{
            T100SAFE_DELETE(m_fstream);
        }
    }else{

    }
}

T100VOID T100BinaryFileAccessor::uninit()
{
    if(m_fstream){
        m_fstream->close();
        T100SAFE_DELETE(m_fstream);
    }
}

T100VOID T100BinaryFileAccessor::SeekRead(T100UINT value)
{

}

T100VOID T100BinaryFileAccessor::Read()
{

}

T100VOID T100BinaryFileAccessor::SeekWrite(T100UINT value)
{

}

T100VOID T100BinaryFileAccessor::Write()
{

}

}
