#ifndef T100BINARYFILE_H
#define T100BINARYFILE_H

#include "T100File.h"

class T100BinaryFile : public T100File
{
    public:
        T100BinaryFile(T100WSTRING);
        virtual ~T100BinaryFile();

    protected:

    private:
};

#endif // T100BINARYFILE_H
