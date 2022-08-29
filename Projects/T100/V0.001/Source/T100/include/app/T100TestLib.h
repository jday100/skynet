#ifndef T100TESTLIB_H
#define T100TESTLIB_H

#include "T100Test.h"
#include "T100TestThread.h"


class T100TestLib : public T100Test
{
    public:
        T100TestLib();
        virtual ~T100TestLib();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_clock();
        T100BOOL                    test_console();
        T100BOOL                    test_file();
        T100BOOL                    test_file_tools();
        T100BOOL                    test_path();
        T100BOOL                    test_string();
        T100BOOL                    test_string_tools();
        T100BOOL                    test_unicode();
        T100BOOL                    test_winconsole();

    private:
        static T100STDSTRING        m_unit;

        T100TestThread              test_thread;
};

#endif // T100TESTLIB_H
