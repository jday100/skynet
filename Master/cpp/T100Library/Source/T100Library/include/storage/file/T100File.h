#ifndef T100FILE_H
#define T100FILE_H

#include "storage/filesystem/T100FileSystemEntry.h"

namespace T100LIBRARY{

class T100File : public T100FileSystemEntry
{
    public:
        T100File(const T100WSTRING&);
        virtual ~T100File();

    protected:

    private:
};

}

#endif // T100FILE_H
