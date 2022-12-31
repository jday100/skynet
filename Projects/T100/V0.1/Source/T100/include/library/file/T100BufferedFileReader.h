#ifndef T100BUFFEREDFILEREADER_H
#define T100BUFFEREDFILEREADER_H

#include "T100FileReader.h"

namespace T100Library{

class T100BufferedFileReader : public T100FileReader
{
    public:
        T100BufferedFileReader(T100WSTRING);
        virtual ~T100BufferedFileReader();

    protected:

    private:
};

}

#endif // T100BUFFEREDFILEREADER_H
