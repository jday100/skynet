#include "T100BigInteger.h"

T100BigInteger::T100BigInteger() :
    T100BigIntegerBase()
{
    //ctor
}

T100BigInteger::T100BigInteger(T100WSTRING& value) :
    T100BigIntegerBase()
{
    //ctor
}

T100BigInteger::T100BigInteger(T100WCHAR* value) :
    T100BigIntegerBase()
{
    //ctor
    T100WSTRING     data    = value;

    Convert(data, m_values);
}

T100BigInteger::~T100BigInteger()
{
    //dtor
}

T100BOOL T100BigInteger::Addition(T100BigInteger& a, T100BigInteger& b, T100BigInteger& c)
{

}

T100VOID T100BigInteger::Clear()
{
    m_values.clear();
    m_sign  = 0;
}

T100BOOL T100BigInteger::operator==(T100BigInteger& value)
{
    if(m_values == value.m_values){
        return T100TRUE;
    }
    return T100FALSE;
}
