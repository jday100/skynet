#ifndef T100FILESYSTEMENTRY_H
#define T100FILESYSTEMENTRY_H

#include "base/T100Class.h"

namespace T100LIBRARY{

class T100FileSystemEntry : public T100Class
{
    public:
        T100FileSystemEntry(const T100WSTRING&);
        virtual ~T100FileSystemEntry();

        virtual T100VOID                SetEntryName(const T100WSTRING&);
        virtual const T100WSTRING&      GetEntryName();

        virtual T100BOOL                IsExists();

    protected:
        T100WSTRING                     m_entryName;

    private:
};

}

#endif // T100FILESYSTEMENTRY_H
