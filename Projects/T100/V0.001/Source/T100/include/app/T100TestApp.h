#ifndef T100TESTAPP_H
#define T100TESTAPP_H

#include "T100Test.h"
#include "T100AllTests.h"
class T100App;

class T100TestApp : public T100Test
{
    public:
        T100TestApp(T100App*);
        virtual ~T100TestApp();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100VOID                    init();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;

        T100TestLog                 test_log;
        T100TestLib                 test_lib;
        T100TestSystem              test_system;
        T100TestQU32                test_qu32;

        T100AssemblyTest            test_assembly;
        T100VPCTest                 test_vpc;
        T100OSTest                  test_os;

        T100BOOL                    test_app();
};

#endif // T100TESTAPP_H
