#ifndef T100UNICODE_H
#define T100UNICODE_H

#include "T100Common.h"
#include "base/T100Class.h"

class T100Unicode : public T100Class
{
    public:
        T100Unicode();
        virtual ~T100Unicode();

        static T100STRING8      to_string8(T100STRING16&);
        static T100STRING16     to_string16(T100STRING8&);

        static T100STRING8      to_string8(T100STRING32&);
        static T100STRING32     to_string32(T100STRING8&);

        static T100STRING16     to_string16(T100STRING32&);
        static T100STRING32     to_string32(T100STRING16&);

        static T100STRING8      to_string8(T100WSTRING&);
        static T100WSTRING      to_wstring(T100STRING8&);

        static T100STRING16     to_string16(T100WSTRING&);
        static T100WSTRING      to_wstring(T100STRING16&);

        static T100STRING32     to_string32(T100WSTRING&);
        static T100WSTRING      to_wstring(T100STRING32&);

    protected:

    private:
};

#endif // T100UNICODE_H
