#ifndef T100EXECUTABLEFILE_H
#define T100EXECUTABLEFILE_H

#include "T100File.h"
#include "T100String.h"
#include "T100ExecutableFileReader.h"
#include "T100ExecutableFileWriter.h"

namespace T100Component{

class T100ExecutableFile : public T100Library::T100File
{
    public:
        T100ExecutableFile(T100STRING);
        virtual ~T100ExecutableFile();

        T100ExecutableFileReader*           getReader();
        T100ExecutableFileWriter*           getWriter();

    protected:

    private:
};

}

#endif // T100EXECUTABLEFILE_H
