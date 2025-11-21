#include "storage/file/binary/T100BinaryFile.h"

#include <io.h>
#include <sys/stat.h>

namespace T100LIBRARY{

T100BinaryFile::T100BinaryFile(const T100WSTRING& name) :
    T100File(name)
{
    //ctor
}

T100BinaryFile::~T100BinaryFile()
{
    //dtor
}

T100BOOL T100BinaryFile::Create()
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

T100BOOL T100BinaryFile::Remove()
{
    T100INT     result;

    result = ::_wremove(m_entryName.c_str());

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BinaryFileReader* T100BinaryFile::CreateReader()
{
    T100BinaryFileReader*       reader      = T100NEW T100BinaryFileReader(*this);

    return reader;
}

T100VOID T100BinaryFile::DestroyReader(T100BinaryFileReader*& reader)
{
    T100SAFE_DELETE(reader);
}

T100BinaryFileWriter* T100BinaryFile::CreateWriter()
{
    T100BinaryFileWriter*       writer      = T100NEW T100BinaryFileWriter(*this);

    return writer;
}

T100VOID T100BinaryFile::DestroyWriter(T100BinaryFileWriter*& writer)
{
    T100SAFE_DELETE(writer);
}

T100BinaryFileAccessor* T100BinaryFile::CreateAccessor()
{
    T100BinaryFileAccessor*     accessor    = T100NEW T100BinaryFileAccessor(*this);

    return accessor;
}

T100VOID T100BinaryFile::DestroyAccessor(T100BinaryFileAccessor*& accessor)
{
    T100SAFE_DELETE(accessor);
}

}
