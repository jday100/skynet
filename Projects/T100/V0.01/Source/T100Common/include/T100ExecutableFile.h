#ifndef T100EXECUTABLEFILE_H
#define T100EXECUTABLEFILE_H

#include "T100File.h"
class T100ExecutableFileReader;
class T100ExecutableFileWriter;


class T100ExecutableFile : public T100File
{
    public:
        T100ExecutableFile(T100String);
        virtual ~T100ExecutableFile();

        T100ExecutableFileReader*           getReader();
        T100ExecutableFileWriter*           getWriter();

    protected:

    private:
};

#endif // T100EXECUTABLEFILE_H
