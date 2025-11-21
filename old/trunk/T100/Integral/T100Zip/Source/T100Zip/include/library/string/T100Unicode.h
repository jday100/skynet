#ifndef T100UNICODE_H
#define T100UNICODE_H

#include "T100Common.h"

class T100Unicode
{
    public:
        T100Unicode();
        virtual ~T100Unicode();

        static T100STRING       ToString8(const T100WSTRING&);
        static T100WSTRING      ToWString(const T100STRING&);

    protected:

    private:
};

#endif // T100UNICODE_H
