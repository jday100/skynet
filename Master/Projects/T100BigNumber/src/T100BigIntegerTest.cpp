#include "T100BigIntegerTest.h"

#include <iostream>
#include "math/big/T100BigInteger.h"
#include "math/big/T100BigIntegerByte.h"

T100BigIntegerTest::T100BigIntegerTest()
{
    //ctor
}

T100BigIntegerTest::~T100BigIntegerTest()
{
    //dtor
}

T100INT T100BigIntegerTest::test()
{
    T100BigInteger      a;
    T100BigInteger      b;
    T100BigInteger      c;

    a = L"1";
    b = L"1";

    //T100BigInteger::Addition(a, b, c);

    if(a == b){
        return 1;
    }

    return 0;
}

T100INT T100BigIntegerTest::byte_test()
{
    T100BigIntegerByte      a(L"111");
    T100BigIntegerByte      b(L"222");
    T100BigIntegerByte      c;

    T100BigIntegerByte::Addition(a, b, c);

    std::wcout << c.ToWString();

    return 0;
}
