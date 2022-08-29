#ifndef T100TEST_H
#define T100TEST_H

#include <unordered_map>
#include "T100Common.h"
class T100Test;

#define     T100TEST_UNIT_HASH      std::unordered_map<T100STDSTRING, T100Test*>
typedef     T100BOOL(T100Test::*T100TEST_UNIT)();


class T100Test
{
    public:
        T100Test(T100STDSTRING);
        virtual ~T100Test();

        virtual T100BOOL            test_all()=0;
        virtual T100BOOL            test_unit(T100STDSTRING);
        virtual T100BOOL            list();

    protected:
        T100VOID                    create();
        T100VOID                    destroy();
        virtual T100VOID            load();
        virtual T100VOID            unload();

        T100VOID                    show_result(T100BOOL, T100STDSTRING);

    private:
        static T100TEST_UNIT_HASH   m_units;
        T100STDSTRING               m_unit;
};

#endif // T100TEST_H
