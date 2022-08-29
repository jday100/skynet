#ifndef T100PARTFILE_H
#define T100PARTFILE_H
#include "T100File.h"
#include "T100PartFileReader.h"
#include "T100PartFileWriter.h"


class T100PartFile : public T100File
{
    public:
        T100PartFile(T100String);
        virtual ~T100PartFile();

        T100PartFileReader*         getReader();
        T100PartFileWriter*         getWriter();

    protected:

    private:
};

#endif // T100PARTFILE_H
