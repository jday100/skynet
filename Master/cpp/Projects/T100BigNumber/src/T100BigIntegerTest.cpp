#include "T100BigIntegerTest.h"

#include <iostream>
#include "math/bignum/T100BigInteger.h"

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
    T100BigInteger          a(L"555");
    T100BigInteger          b(L"666");
    T100BigInteger          c;

    T100BigInteger::Addition(a, b, c);

    std::wcout << c.ToWString();

    return 0;
}
