#ifndef T100NTFILE_H
#define T100NTFILE_H

#include "storage/file/binary/T100BinaryFile.h"

namespace T100LIBRARY{

class T100NTFile : public T100BinaryFile
{
    public:
        T100NTFile(const T100WSTRING&);
        virtual ~T100NTFile();

        virtual T100BOOL            Save();

    protected:

    private:
};

}

#endif // T100NTFILE_H
