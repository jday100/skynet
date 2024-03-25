#ifndef T100BUFFEREDFILE_H
#define T100BUFFEREDFILE_H

#include "T100Common.h"
#include "T100File.h"

class T100BufferedFile : public T100File
{
    public:
        T100BufferedFile(T100STRING);
        virtual ~T100BufferedFile();

    protected:

    private:
};

#endif // T100BUFFEREDFILE_H
