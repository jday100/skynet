#ifndef T100BUFFEREDFILE_H
#define T100BUFFEREDFILE_H

#include "T100File.h"

namespace T100Library{
class T100BufferedFileReader;
class T100BufferedFileWriter;
class T100BufferedFileStream;


class T100BufferedFile : public T100File
{
    public:
        T100BufferedFile(T100WSTRING);
        virtual ~T100BufferedFile();

        T100BufferedFileReader*         getReader();
        T100BufferedFileWriter*         getWriter();
        T100BufferedFileStream*         getStream();

    protected:

    private:
};

}

#endif // T100BUFFEREDFILE_H
