#ifndef T100ASSEMBLYTESTDRAFTS_H
#define T100ASSEMBLYTESTDRAFTS_H

#include "T100Test.h"
class T100App;


class T100AssemblyTestDrafts :  public T100Test
{
    public:
        T100AssemblyTestDrafts(T100App*);
        virtual ~T100AssemblyTestDrafts();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    test_multifile();

        T100BOOL                    test_multisegment();

        T100BOOL                    test_cross_segment();

        T100BOOL                    test_cross();

        T100BOOL                    test_int();

        T100BOOL                    test_exe();

        T100BOOL                    test_share();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app           = T100NULL;

};

#endif // T100ASSEMBLYTESTDRAFTS_H
