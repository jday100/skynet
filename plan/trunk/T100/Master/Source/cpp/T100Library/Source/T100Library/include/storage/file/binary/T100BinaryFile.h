#ifndef T100BINARYFILE_H
#define T100BINARYFILE_H

#include "storage/file/T100File.h"
#include "storage/file/binary/T100BinaryFileReader.h"
#include "storage/file/binary/T100BinaryFileWriter.h"
#include "storage/file/binary/T100BinaryFileAccessor.h"

namespace T100LIBRARY{

class T100BinaryFile : public T100File
{
    public:
        T100BinaryFile(const T100WSTRING&);
        virtual ~T100BinaryFile();

        virtual T100BOOL                        Create();
        virtual T100BOOL                        Remove();

        virtual T100BinaryFileReader*           CreateReader();
        virtual T100VOID                        DestroyReader(T100BinaryFileReader*&);

        virtual T100BinaryFileWriter*           CreateWriter();
        virtual T100VOID                        DestroyWriter(T100BinaryFileWriter*&);

        virtual T100BinaryFileAccessor*         CreateAccessor();
        virtual T100VOID                        DestroyAccessor(T100BinaryFileAccessor*&);

    protected:

    private:
};

}

#endif // T100BINARYFILE_H
