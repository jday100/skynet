#ifndef T100HINT_H
#define T100HINT_H

#include "T100Common.h"


class T100Hint
{
    public:
        T100Hint();
        virtual ~T100Hint();

        static T100STDSTRING        hex(T100BYTE&);
        static T100STDSTRING        hex(T100WORD&);
        static T100STDSTRING        dec(T100BYTE&);
        static T100STDSTRING        dec(T100WORD&);

        static T100BOOL             m_detail;

    protected:


    private:
};

#endif // T100HINT_H
