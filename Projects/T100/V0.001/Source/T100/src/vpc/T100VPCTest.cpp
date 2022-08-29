#include "T100VPCTest.h"

#include "T100Setup.h"
#include "T100Order.h"
#include "T100VPCApp.h"

T100STDSTRING       T100VPCTest::m_unit         = "vpc";


T100VPCTest::T100VPCTest()
    :T100Test(m_unit)
{
    //ctor
}

T100VPCTest::~T100VPCTest()
{
    //dtor
}

T100VOID T100VPCTest::load()
{

}

T100WORD T100VPCTest::order(T100ORDER_TYPE type)
{
    T100WORD_BITS   result;

    result.BYTE0.BYTE   = type;

    return result.WORD;
}

T100WORD T100VPCTest::jump()
{
    T100WORD_BITS   result;

    result.BYTE0.BYTE   = T100ORDER_JUMP;
    result.BYTE1.BYTE   = T_NONE;
    result.BYTE2.BYTE   = T_IMM;

    return result.WORD;
}

T100WORD T100VPCTest::jump(T100OPERATE_TYPE base, T100OPERATE_TYPE op)
{
    T100WORD_BITS   result;

    result.BYTE0.BYTE   = T100ORDER_JUMP;
    result.BYTE1.BYTE   = base;
    result.BYTE2.BYTE   = op;

    return result.WORD;
}

T100WORD T100VPCTest::in(T100OPERATE_TYPE target, T100OPERATE_TYPE source)
{
    /*
    T100Order   order;

    order.setOrder(T100ORDER_IN);
    order.setTargetBaseType(T_NONE);
    order.setTargetOffsetType(target);
    order.setSourceBaseType(T_NONE);
    order.setSourceOffsetType(source);

    return order.getWORD();
    */
}

T100WORD T100VPCTest::out(T100OPERATE_TYPE target, T100OPERATE_TYPE source)
{
    /*
    T100Order   order;

    order.setOrder(T100ORDER_OUT);
    order.setTargetBaseType(T_NONE);
    order.setTargetOffsetType(target);
    order.setSourceBaseType(T_NONE);
    order.setSourceOffsetType(source);

    return order.getWORD();
    */
}

T100WORD T100VPCTest::move(T100OPERATE_TYPE target, T100OPERATE_TYPE source)
{
    /*
    T100Order   order;

    order.setOrder(T100ORDER_MOVE);
    order.setTargetBaseType(T_NONE);
    order.setTargetOffsetType(target);
    order.setSourceBaseType(T_NONE);
    order.setSourceOffsetType(source);

    return order.getWORD();
    */
}

T100BOOL T100VPCTest::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!test_vpc()){
        result = T100FALSE;
    }

    if(!test_hard()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100VPCTest::test_vpc()
{
    T100BOOL        result      = T100TRUE;
    T100VPCApp      vpc;

    vpc.show();

    return result;
}

T100BOOL T100VPCTest::test_hard()
{
    T100BOOL        result      = T100TRUE;
    T100BOOL        value;
    T100VPCApp      vpc;
    T100STDSTRING   file;

    T100WORD_VECTOR     app;
    T100WORD*           data;

    T100WORD            cmd;
    T100WORD            data1, data2;
    T100WORD            read;
    T100WORD            flag;
    T100WORD            offset;

    cmd     = 16;
    data1   = 17;
    data2   = 18;
    read    = 17;
    flag    = 101;
    offset  = 1024;

    app.resize(200);
    data = app.data();

    data[0]     =   jump();
    data[1]     =   2;
    data[2]     =   out(T_IMM, T_IMM);
    data[3]     =   data1;
    data[4]     =   0;
    data[5]     =   out(T_IMM, T_IMM);
    data[6]     =   data2;
    data[7]     =   0;
    data[8]     =   out(T_IMM, T_IMM);
    data[9]     =   cmd;
    data[10]    =   read;
    data[11]    =   in(T_MEM, T_IMM);
    data[12]    =   flag;
    data[13]    =   offset;

    data[100]   =   order(T100ORDER_HALT);

    if(vpc.show()){
        file = T100APP_TEST_PATH + "\\" + "";
        //value = vpc.run(file);
        value = vpc.run(app, 0);
        if(!value){
            result = T100FALSE;
        }
    }else{
        result = T100FALSE;
    }

    return result;
}
