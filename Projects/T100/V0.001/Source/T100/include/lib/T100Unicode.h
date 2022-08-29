#ifndef T100UNICODE_H
#define T100UNICODE_H

#include "T100Common.h"


class T100Unicode
{
    public:
        T100Unicode();
        virtual ~T100Unicode();

        static T100STDSTRING        to_utf8(T100STDSTRING32);
        static T100STDSTRING32      to_utf32(T100STDSTRING);

        static T100STDSTRING        gbk_to_utf8(T100STDSTRING);

    protected:

    private:
};

#endif // T100UNICODE_H
