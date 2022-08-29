#ifndef T100FONTTEST_H
#define T100FONTTEST_H

#include "T100Test.h"


class T100FontTest : public T100Test
{
    public:
        T100FontTest();
        virtual ~T100FontTest();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    test_file();
        T100BOOL                    test_font();

        T100BOOL                    test_read();
        T100BOOL                    test_write();

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100FONTTEST_H
