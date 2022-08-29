#ifndef T100REALFILE_H
#define T100REALFILE_H

#include "T100ProduceFile.h"
#include "T100RealFileReader.h"
#include "T100RealFileWriter.h"


class T100RealFile : public T100ProduceFile
{
    public:
        T100RealFile(T100STRING);
        virtual ~T100RealFile();

        T100RealFileReader*         getReader();
        T100RealFileWriter*         getWriter();

    protected:

    private:
};

#endif // T100REALFILE_H
