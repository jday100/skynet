#ifndef T100BUFFEREDFILEWRITER_H
#define T100BUFFEREDFILEWRITER_H

#include "T100FileWriter.h"

namespace T100Library{

class T100BufferedFileWriter : public T100FileWriter
{
    public:
        T100BufferedFileWriter(T100WSTRING);
        virtual ~T100BufferedFileWriter();

    protected:

    private:
};

}

#endif // T100BUFFEREDFILEWRITER_H
