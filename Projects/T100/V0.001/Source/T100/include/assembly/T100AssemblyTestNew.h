#ifndef T100ASSEMBLYTESTNEW_H
#define T100ASSEMBLYTESTNEW_H

#include "T100Test.h"
class T100App;


class T100AssemblyTestNew : public T100Test
{
    public:
        T100AssemblyTestNew(T100App*);
        virtual ~T100AssemblyTestNew();

        T100BOOL                    test_all();

    protected:
        T100BOOL                    test_label();

        T100BOOL                    test_tiny();
        T100BOOL                    test_big();
        //
        T100BOOL                    test_dll();
        T100BOOL                    test_sll();
        //
        T100BOOL                    test_virtual();
        T100BOOL                    test_share();

        T100BOOL                    test_exe();

        T100BOOL                    test_variable();

    private:
        static T100STDSTRING        m_unit;
        T100App*                    m_app           = T100NULL;
};

#endif // T100ASSEMBLYTESTNEW_H
