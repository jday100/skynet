#ifndef T100DEPLOYBTEST_H
#define T100DEPLOYBTEST_H

#include "T100Test.h"

namespace T100{

class T100DeployBTest : public T100Library::T100Test
{
    public:
        T100DeployBTest(T100Test*);
        virtual ~T100DeployBTest();

    protected:
        T100BOOL            do_test();

        T100BOOL            deploy_font();
        T100BOOL            deploy_rom();
        T100BOOL            deploy_boot();
        T100BOOL            deploy_init();
        T100BOOL            deploy_kernel();
        T100BOOL            deploy_vdisk();

        T100BOOL            deploy_run();

    private:
        static T100WSTRING                      m_name;

};

}

#endif // T100DEPLOYBTEST_H
