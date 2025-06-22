#ifndef T100TEXTFILE_H
#define T100TEXTFILE_H

#include "storage/file/T100File.h"
#include "storage/file/text/T100TextFileReader.h"
#include "storage/file/text/T100TextFileWriter.h"
#include "storage/file/text/T100TextFileReaderW.h"
#include "storage/file/text/T100TextFileWriterW.h"
#include "storage/file/text/T100TextFileAccessor.h"

namespace T100LIBRARY{

class T100TextFile : public T100File
{
    public:
        T100TextFile(const T100WSTRING&);
        virtual ~T100TextFile();

        virtual T100BOOL                        Create();
        virtual T100BOOL                        Remove();

        virtual T100TextFileReader*             CreateReader();
        virtual T100VOID                        DestroyReader(T100TextFileReader*&);

        virtual T100TextFileWriter*             CreateWriter();
        virtual T100VOID                        DestroyWriter(T100TextFileWriter*&);

        virtual T100TextFileAccessor*           CreateAccessor();
        virtual T100VOID                        DestroyAccessor(T100TextFileAccessor*&);

        virtual T100TextFileReaderW*            CreateReaderW();
        virtual T100VOID                        DestroyReaderW(T100TextFileReaderW*&);

        virtual T100TextFileWriterW*            CreateWriterW();
        virtual T100VOID                        DestroyWriterW(T100TextFileWriterW*&);

    protected:

    private:
};

}

#endif // T100TEXTFILE_H
