#include "T100BigIntegerBase.h"

#include "T100BigInteger.h"
#include "T100BitCommon.h"

T100BigIntegerBase::T100BigIntegerBase() :
    T100Class()
{
    //ctor
}

T100BigIntegerBase::~T100BigIntegerBase()
{
    //dtor
}

T100BOOL T100BigIntegerBase::Convert(T100WSTRING& digital, T100BIGINTEGER_VALUE_VECTOR& values)
{
    T100INT     length  = digital.size();

    T100WCHAR   letter  = digital[0];

    Convert(letter, 1, values);
}

T100BOOL T100BigIntegerBase::Convert(T100WCHAR letter, T100UINT value, T100BIGINTEGER_VALUE_VECTOR& data)
{
    switch(letter){
    case '0':
        {

        }
        break;
    case '1':
        {
            return ConvertOne(value, data);
        }
        break;
    case '2':
        {

        }
        break;
    case '3':
        {

        }
        break;
    case '4':
        {

        }
        break;
    case '5':
        {

        }
        break;
    case '6':
        {

        }
        break;
    case '7':
        {

        }
        break;
    case '8':
        {

        }
        break;
    case '9':
        {

        }
        break;
    case '+':
        {

        }
        break;
    case '-':
        {

        }
        break;
    }
}

T100BOOL T100BigIntegerBase::ConvertOne(T100UINT value, T100BIGINTEGER_VALUE_VECTOR& data)
{
    T100UINT    item    = 1;

    data.push_back(item);
}

T100BOOL T100BigIntegerBase::Multiply(T100BigInteger& source, T100UINT value, T100BigInteger& target)
{
    target.Clear();
    for(T100UINT item : source.m_values){
        T100DWORD_BIT   result;
        result.DWORD  = item * value;

        if(result.WORD_HIGH == 0){
            target.m_values.push_back(result.WORD_LOW);
        }else{
            target.m_values.push_back(result.WORD_LOW);
            target.m_values.push_back(result.WORD_HIGH);
        }
    }
}
