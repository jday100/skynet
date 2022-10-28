#ifndef T100FILESTREAM_H
#define T100FILESTREAM_H

#include "T100Stream.h"

namespace T100Library{

class T100FileStream : public T100Stream
{
    public:
        T100FileStream(T100WSTRING);
        virtual ~T100FileStream();

    protected:
        T100WSTRING                 m_file;

    private:
};

}

#endif // T100FILESTREAM_H
