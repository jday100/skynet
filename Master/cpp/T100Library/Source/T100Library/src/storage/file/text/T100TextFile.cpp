#include "storage/file/text/T100TextFile.h"

#include <io.h>
#include <sys/stat.h>

namespace T100LIBRARY{

T100TextFile::T100TextFile(const T100WSTRING& name) :
    T100File(name)
{
    //ctor
}

T100TextFile::~T100TextFile()
{
    //dtor
}

T100BOOL T100TextFile::Create()
{
    T100INT         result;

    result  = ::_wcreat(m_entryName.c_str(), _S_IRWXU);

    if(-1 == result){

    }else{
        result = ::_close(result);

        if(-1 == result){

        }else{
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100TextFile::Remove()
{
    T100INT     result;

    result = ::_wremove(m_entryName.c_str());

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100TextFileReader* T100TextFile::CreateReader()
{
    T100TextFileReader*     reader      = T100NEW T100TextFileReader(*this);

    return reader;
}

T100VOID T100TextFile::DestroyReader(T100TextFileReader*& reader)
{
    T100SAFE_DELETE(reader);
}

T100TextFileWriter* T100TextFile::CreateWriter()
{
    T100TextFileWriter*     writer      = T100NEW T100TextFileWriter(*this);

    return writer;
}

T100VOID T100TextFile::DestroyWriter(T100TextFileWriter*& writer)
{
    T100SAFE_DELETE(writer);
}

T100TextFileAccessor* T100TextFile::CreateAccessor()
{
    T100TextFileAccessor*   accessor    = T100NEW T100TextFileAccessor(*this);

    return accessor;
}

T100VOID T100TextFile::DestroyAccessor(T100TextFileAccessor*& accessor)
{
    T100SAFE_DELETE(accessor);
}

T100TextFileReaderW* T100TextFile::CreateReaderW()
{
    T100TextFileReaderW*    reader      = T100NEW T100TextFileReaderW(*this);

    return reader;
}

T100VOID T100TextFile::DestroyReaderW(T100TextFileReaderW*& reader)
{
    T100SAFE_DELETE(reader);
}

T100TextFileWriterW* T100TextFile::CreateWriterW()
{
    T100TextFileWriterW*    writer      = T100NEW T100TextFileWriterW(*this);

    return writer;
}

T100VOID T100TextFile::DestroyWriterW(T100TextFileWriterW*& writer)
{
    T100SAFE_DELETE(writer);
}

}
