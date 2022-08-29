#ifndef T100CMDLINETEST_H
#define T100CMDLINETEST_H

#include "T100Test.h"


class T100CmdLineTest : public T100Test
{
    public:
        T100CmdLineTest(T100Test*);
        virtual ~T100CmdLineTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    do_init();
        T100BOOL                    do_uninit();

        T100BOOL                    test_string();

        T100BOOL                    test_char();

        T100BOOL                    test_parameter();

        T100BOOL                    test_cmdline();

    private:
        static T100WSTRING          m_name;

        T100WSTRING                 m_exec          = L"T100Lib.exe";
        T100WSTRING                 m_switch        = L"-t";
        T100WSTRING                 m_option        = L"-l";
        T100WSTRING                 m_value         = L"lib.a";
        T100WSTRING                 m_source        = L"source.txt";
        T100WSTRING                 m_target        = L"target.bin";

        T100WCHAR*                  m_argv[6];

};

#endif // T100CMDLINETEST_H
