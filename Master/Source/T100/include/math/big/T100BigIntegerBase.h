#ifndef T100BIGINTEGERBASE_H
#define T100BIGINTEGERBASE_H

#include <vector>
#include "base/T100Class.h"

class T100BigInteger;

#define     T100BIGINTEGER_VALUE_VECTOR             std::vector<T100UINT>

class T100BigIntegerBase : public T100Class
{
    public:
        T100BigIntegerBase();
        virtual ~T100BigIntegerBase();

    protected:
        T100BOOL            Convert(T100WSTRING&, T100BIGINTEGER_VALUE_VECTOR&);
        T100BOOL            Convert(T100WCHAR, T100UINT, T100BIGINTEGER_VALUE_VECTOR&);

    private:
        T100BOOL            ConvertOne(T100UINT, T100BIGINTEGER_VALUE_VECTOR&);

        T100BOOL            Multiply(T100BigInteger&, T100UINT, T100BigInteger&);
};

#endif // T100BIGINTEGERBASE_H
