#ifndef T100ASSEMBLYTEST_H
#define T100ASSEMBLYTEST_H

#include "T100Test.h"
#include "T100AsmTestExe.h"
#include "T100AssemblyTestNew.h"
#include "T100AssemblyTestDrafts.h"
class T100App;

class T100AssemblyTest : public T100Test
{
    public:
        T100AssemblyTest(T100App*);
        virtual ~T100AssemblyTest();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    test_byte();
        T100BOOL                    test_byte_empty();
        T100BOOL                    test_byte_one();

        T100BOOL                    test_char();
        T100BOOL                    test_string();
        T100BOOL                    test_keyword();

        T100BOOL                    test_sentence();
        T100BOOL                    test_segment();
        T100BOOL                    test_file();

        T100BOOL                    test_assembly();

        T100BOOL                    test_jump();
        T100BOOL                    test_complexus();

        T100BOOL                    test_move();

        T100BOOL                    test_io();

        T100AsmTestExe              test_exe;

        T100AssemblyTestNew         test_new;

        T100AssemblyTestDrafts      test_drafts;

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;
};

#endif // T100ASSEMBLYTEST_H
