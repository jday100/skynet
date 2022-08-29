#ifndef T100ASMTESTEXE_H
#define T100ASMTESTEXE_H

#include "T100Test.h"
class T100App;


class T100AsmTestExe : public T100Test
{
    public:
        T100AsmTestExe(T100App*);
        virtual ~T100AsmTestExe();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    test_exe();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app       = T100NULL;
};

#endif // T100ASMTESTEXE_H
