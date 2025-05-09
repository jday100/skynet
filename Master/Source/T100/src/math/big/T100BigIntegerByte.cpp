#include "T100BigIntegerByte.h"



T100BigIntegerByte::T100BigIntegerByte()
{
    //ctor
}

T100BigIntegerByte::T100BigIntegerByte(T100WCHAR* data)
{
    //ctor
    T100WSTRING     temp    = data;
    Convert(temp);
}

T100BigIntegerByte::T100BigIntegerByte(T100WSTRING& data)
{
    //ctor
    Convert(data);
}

T100BigIntegerByte::~T100BigIntegerByte()
{
    //dtor
}

T100BOOL T100BigIntegerByte::Convert(T100WSTRING& data)
{
    T100UINT    length      = data.size();
    T100BOOL    flag        = T100FALSE;

    for(T100UINT i = 0; i < length; i++){
        T100WCHAR   letter  = data[i];
        ConvertLetter(letter, flag);
    }
}

T100BOOL T100BigIntegerByte::ConvertLetter(T100WCHAR letter, T100BOOL& flag)
{
    T100BYTE_BIT        data;

    flag    = !flag;

    switch(letter){
    case L'0':
        {
            Assign(T100DIGIT_ZERO, flag);
        }
        break;
    case L'1':
        {
            Assign(T100DIGIT_ONE, flag);
        }
        break;
    case L'2':
        {
            Assign(T100DIGIT_TWO, flag);
        }
        break;
    case L'3':
        {
            Assign(T100DIGIT_THREE, flag);
        }
        break;
    case L'4':
        {
            Assign(T100DIGIT_FOUR, flag);
        }
        break;
    case L'5':
        {
            Assign(T100DIGIT_FIVE, flag);
        }
        break;
    case L'6':
        {
            Assign(T100DIGIT_SIX, flag);
        }
        break;
    case L'7':
        {
            Assign(T100DIGIT_SEVEN, flag);
        }
        break;
    case L'8':
        {
            Assign(T100DIGIT_EIGHT, flag);
        }
        break;
    case L'9':
        {
            Assign(T100DIGIT_NINE, flag);
        }
        break;
    case L'+':
        {
            m_sign  = T100SIGN_PLUS;
        }
        break;
    case L'-':
        {
            m_sign  = T100SIGN_MINUS;
        }
        break;
    }
}

T100BOOL T100BigIntegerByte::Assign(T100DIGIT_TYPE data, T100BOOL flag)
{
    T100BYTE_BIT        item;

    if(flag){
        item.BYTE_LOW4      = data;
        m_values.push_back(item);
    }else{
        T100BYTE_BIT&   temp    = m_values[0];
        temp.BYTE_HIGH4     = data;
    }
}

T100BOOL T100BigIntegerByte::Addition(T100BigIntegerByte& source1, T100BigIntegerByte& source2, T100BigIntegerByte& target)
{
    T100UINT    length;
    T100BOOL    flag        = T100FALSE;

    length  = source1.m_values.size() > source2.m_values.size() ? source2.m_values.size() : source1.m_values.size();

    for(T100UINT i = 0; i < length; i++){
        T100BYTE_BIT    b1      = source1[i];
        T100BYTE_BIT    b2      = source2[i];
        T100BYTE_BIT    result;

        Addition(b1, b2, result, flag);

        target.m_values.push_back(result);
    }
}

T100BOOL T100BigIntegerByte::Addition(T100BYTE_BIT& source1, T100BYTE_BIT& source2, T100BYTE_BIT& target, T100BOOL& flag)
{
    T100BOOL        carry       = T100FALSE;
    T100BYTE_BIT    value;

    value.BYTE      = source1.BYTE_LOW4 + source2.BYTE_LOW4;

    if(value.BYTE_HIGH4 > 0){
        carry   = T100TRUE;
    }

    target.BYTE_LOW4    = value.BYTE_LOW4;
    value.BYTE          = source1.BYTE_HIGH4 + source2.BYTE_HIGH4;

    if(carry){
        value.BYTE++;
    }

    target.BYTE_HIGH4   = value.BYTE_LOW4;

    if(value.BYTE_HIGH4 > 0){
        flag    = T100TRUE;
    }else{
        flag    = T100FALSE;
    }

    return T100TRUE;
}

T100UINT T100BigIntegerByte::size()
{
    return m_values.size() * 2;
}

T100BYTE_BIT& T100BigIntegerByte::operator[](T100UINT index)
{
    return m_values[index];
}

T100WSTRING T100BigIntegerByte::ToWString()
{
    T100WSTRING     result;

    T100UINT    length  = m_values.size();

    for(T100INT i = length - 1; i >= 0; i--){
        T100BYTE_BIT&   value   = m_values[i];
        ConvertToWChars(value, result);
    }

    return result;
}

T100BOOL T100BigIntegerByte::ConvertToWChars(T100BYTE_BIT& source, T100WSTRING& target)
{
    T100WCHAR   value;

    value   = ConvertToWChar(source.BYTE_HIGH4);

    target  += value;

    value   = ConvertToWChar(source.BYTE_LOW4);

    target  += value;
}

T100WCHAR T100BigIntegerByte::ConvertToWChar(T100BYTE value)
{
    switch(value){
    case 0:
        {
            return L'0';
        }
        break;
    case 1:
        {
            return L'1';
        }
        break;
    case 2:
        {
            return L'2';
        }
        break;
    case 3:
        {
            return L'3';
        }
        break;
    case 4:
        {
            return L'4';
        }
        break;
    case 5:
        {
            return L'5';
        }
        break;
    case 6:
        {
            return L'6';
        }
        break;
    case 7:
        {
            return L'7';
        }
        break;
    case 8:
        {
            return L'8';
        }
        break;
    case 9:
        {
            return L'9';
        }
        break;
    default:
        {
            return L'#';
        }
        break;
    }
}
