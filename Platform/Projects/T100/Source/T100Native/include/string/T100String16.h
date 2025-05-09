#ifndef T100STRING16_H
#define T100STRING16_H

#include "T100Common.h"

class T100String16
{
    friend class T100String16Hash;
    friend class T100String16Equal;
    public:
        T100String16();
        T100String16(const char*);
        T100String16(const wchar_t*);
        virtual ~T100String16();

        T100WSTRING             to_wstring();
        T100STRING16&           value();

        T100VOID                clear();

    public:
        T100String16&           operator  = (const T100WSTRING&);

    protected:

    private:
        T100STRING16            m_value;
};

#endif // T100STRING16_H
