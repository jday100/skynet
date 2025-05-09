#ifndef T100BIGINTEGER_H
#define T100BIGINTEGER_H

#include <vector>
#include "math/big/T100BigIntegerBase.h"


class T100BigInteger : public T100BigIntegerBase
{
    friend class T100BigIntegerBase;
    public:
        T100BigInteger();
        T100BigInteger(T100WSTRING&);
        T100BigInteger(T100WCHAR*);
        virtual ~T100BigInteger();

        static T100BOOL                     Addition(T100BigInteger&, T100BigInteger&, T100BigInteger&);

        static T100BOOL                     Multiply();

        T100VOID                            Clear();

        T100BOOL                            operator==(T100BigInteger&);

    protected:
        T100BIGINTEGER_VALUE_VECTOR         m_values;
        T100INT                             m_sign          = 0;

    private:
};

#endif // T100BIGINTEGER_H
