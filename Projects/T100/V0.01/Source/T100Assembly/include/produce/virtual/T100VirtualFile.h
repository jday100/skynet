#ifndef T100VIRTUALFILE_H
#define T100VIRTUALFILE_H

#include "T100ProduceFile.h"
#include "T100VirtualFileReader.h"
#include "T100VirtualFileWriter.h"


class T100VirtualFile : public T100ProduceFile
{
    public:
        T100VirtualFile(T100STRING);
        virtual ~T100VirtualFile();

        T100VirtualFileReader*          getReader();
        T100VirtualFileWriter*          getWriter();

    protected:

    private:
};

#endif // T100VIRTUALFILE_H
