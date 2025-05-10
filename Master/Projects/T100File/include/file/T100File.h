#ifndef T100FILE_H
#define T100FILE_H

#include "T100DirectoryEntry.h"

class T100File : public T100DirectoryEntry
{
    public:
        T100File(T100WSTRING);
        virtual ~T100File();

    protected:

    private:
};

#endif // T100FILE_H
