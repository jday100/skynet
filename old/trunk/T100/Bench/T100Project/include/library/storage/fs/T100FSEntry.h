#ifndef T100FSENTRY_H
#define T100FSENTRY_H

#include "T100Common.h"

class T100FSEntry
{
    public:
        T100FSEntry(const T100WSTRING&);
        virtual ~T100FSEntry();

        virtual T100VOID                SetEntryName(const T100WSTRING&);
        virtual const T100WSTRING&      GetEntryName();

        virtual T100BOOL                IsExists();

    protected:
        T100WSTRING                     m_entryName;

    private:
};

#endif // T100FSENTRY_H
