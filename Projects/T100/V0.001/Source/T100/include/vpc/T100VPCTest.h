#ifndef T100VPCTEST_H
#define T100VPCTEST_H

#include "T100Test.h"
#include "T100OrderTypes.h"


class T100VPCTest : public T100Test
{
    public:
        T100VPCTest();
        virtual ~T100VPCTest();

        T100BOOL                    test_all();

    protected:
        T100VOID                    load();

        T100BOOL                    test_vpc();

        T100BOOL                    test_hard();

        T100WORD                    order(T100ORDER_TYPE);
        T100WORD                    jump();
        T100WORD                    jump(T100OPERATE_TYPE, T100OPERATE_TYPE);

        T100WORD                    in(T100OPERATE_TYPE, T100OPERATE_TYPE);
        T100WORD                    out(T100OPERATE_TYPE, T100OPERATE_TYPE);
        T100WORD                    move(T100OPERATE_TYPE, T100OPERATE_TYPE);

    private:
        static T100STDSTRING        m_unit;
};

#endif // T100VPCTEST_H
