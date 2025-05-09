#ifndef T100BIGINTEGERBYTE_H
#define T100BIGINTEGERBYTE_H

#include <vector>
#include "T100Common.h"
#include "common/T100BitCommon.h"
#include "common/T100MathCommon.h"

#define     T100BYTE_BIT_VECTOR         std::vector<T100BYTE_BIT>

class T100BigIntegerByte
{
    public:
        T100BigIntegerByte();
        T100BigIntegerByte(T100WCHAR*);
        T100BigIntegerByte(T100WSTRING&);
        virtual ~T100BigIntegerByte();

        static T100BOOL             Addition(T100BigIntegerByte&, T100BigIntegerByte&, T100BigIntegerByte&);
        static T100BOOL             Subtract();
        static T100BOOL             Multiply();
        static T100BOOL             Divide();

        T100UINT                    size();
        T100WSTRING                 ToWString();

        T100BYTE_BIT&               operator[](T100UINT);

    protected:
        T100BYTE_BIT_VECTOR         m_values;
        T100INT                     m_sign          = 0;

    private:
        T100BOOL                    Convert(T100WSTRING&);
        T100BOOL                    ConvertLetter(T100WCHAR, T100BOOL&);
        T100BOOL                    Assign(T100DIGIT_TYPE, T100BOOL);
        T100BOOL                    ConvertToWChars(T100BYTE_BIT&, T100WSTRING&);
        T100WCHAR                   ConvertToWChar(T100BYTE);
        static T100BOOL             Addition(T100BYTE_BIT&, T100BYTE_BIT&, T100BYTE_BIT&, T100BOOL&);
};

#endif // T100BIGINTEGERBYTE_H
