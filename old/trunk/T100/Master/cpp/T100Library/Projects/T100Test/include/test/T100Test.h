#ifndef T100TEST_H
#define T100TEST_H

#include "T100TestBase.h"

namespace T100LIBRARY{

T100INT         ToValue(T100BOOL);
T100BOOL        ToBool(T100INT);
T100BOOL        ToBool(T100UINT);

class T100Test : public T100TestBase
{
    public:
        T100Test(T100Test* parent = T100NULL, const T100WSTRING& label = L"all");
        virtual ~T100Test();

        virtual T100BOOL            TestAll();
        virtual T100BOOL            TestUnit(const T100WSTRING&);

        virtual T100VOID            List();
        virtual T100BOOL            Find(const T100WSTRING&);

    protected:
        virtual T100VOID            Add(T100Test*, const T100WSTRING&);

    private:
        T100Vessel<T100WSTRING, T100Test*>          m_tests;
};

}

#endif // T100TEST_H
