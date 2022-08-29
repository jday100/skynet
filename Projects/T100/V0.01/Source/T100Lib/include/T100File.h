#ifndef T100FILE_H
#define T100FILE_H

#include "T100DirectoryEntry.h"
#include "T100Stream.h"


class T100File : public T100DirectoryEntry
{
    public:
        T100File(T100WSTRING);
        virtual ~T100File();

        virtual T100BOOL            create();
        virtual T100BOOL            remove();

    protected:
        T100DWORD                   m_length            = 0;

    private:
};

#endif // T100FILE_H
