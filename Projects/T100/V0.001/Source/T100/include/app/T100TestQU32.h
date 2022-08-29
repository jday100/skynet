#ifndef T100TESTQU32_H
#define T100TESTQU32_H

#include "T100Test.h"


class T100TestQU32 : public T100Test
{
    public:
        T100TestQU32();
        virtual ~T100TestQU32();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_qu32();

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100TESTQU32_H
