#ifndef T100UNICODE_H
#define T100UNICODE_H

#include "T100Common.h"

class T100Unicode
{
    public:
        T100Unicode();
        virtual ~T100Unicode();

        static T100STRING8      ToString8(T100WSTRING&);
        static T100WSTRING      ToWString(T100STRING8&);

    protected:

    private:
};

#endif // T100UNICODE_H
