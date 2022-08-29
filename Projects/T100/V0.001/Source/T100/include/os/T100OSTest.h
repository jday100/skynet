#ifndef T100OSTEST_H
#define T100OSTEST_H

#include "T100Test.h"
#include "T100OSTestLib.h"
#include "T100OSTestFS.h"
#include "T100OSTestBoot.h"
#include "T100OSTestKernel.h"
class T100App;

class T100OSTest : public T100Test
{
    public:
        T100OSTest(T100App*);
        virtual ~T100OSTest();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;

        T100OSTestLib               test_lib;
        T100OSTestFS                test_fs;
        T100OSTestBoot              test_boot;
        T100OSTestKernel            test_kernel;
};

#endif // T100OSTEST_H
