#ifndef T100FILEINFO_H
#define T100FILEINFO_H

#include "T100Common.h"

#define T100FILE_VECTOR     std::vector<T100FileInfo*>

enum T100FILE_TYPE{
    T100FILE_NORMAL     = 0x00,
    T100FILE_READONLY   = 0x01,
    T100FILE_HIDDEN     = 0x02,
    T100FILE_SYSTEM     = 0x04,
    T100FILE_SUBDIR     = 0x10,
    T100FILE_ARCH       = 0x20
};


class T100FileInfo
{
    public:
        T100FileInfo();
        virtual ~T100FileInfo();

        T100STDSTRING       path;
        T100STDSTRING       name;
        T100WORD            size;

        T100BOOL            READONLY        = T100FALSE;
        T100BOOL            HIDDEN          = T100FALSE;
        T100BOOL            SYSTEM          = T100FALSE;
        T100BOOL            SUBDIR          = T100FALSE;
        T100BOOL            ARCH            = T100FALSE;

    protected:

    private:
};

#endif // T100FILEINFO_H
