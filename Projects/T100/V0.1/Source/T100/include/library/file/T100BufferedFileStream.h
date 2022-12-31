#ifndef T100BUFFEREDFILESTREAM_H
#define T100BUFFEREDFILESTREAM_H

#include "T100FileStream.h"

namespace T100Library{

class T100BufferedFileStream : public T100FileStream
{
    public:
        T100BufferedFileStream(T100WSTRING);
        virtual ~T100BufferedFileStream();

    protected:

    private:
};

}

#endif // T100BUFFEREDFILESTREAM_H
