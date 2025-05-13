#ifndef T100TEST_H
#define T100TEST_H

#include "test/T100TestBase.h"

class T100Test : public T100TestBase
{
    public:
        T100Test(T100Test*, T100WSTRING name = L"all");
        virtual ~T100Test();

        T100VOID                SetGlobalInit(T100BOOL);
        T100VOID                SetGlobalUninit(T100BOOL);

        T100VOID                SetInit(T100BOOL);
        T100VOID                SetUninit(T100BOOL);

        virtual T100RESULT      TestAll();
        virtual T100RESULT      TestUnit(T100WSTRING);

        virtual T100VOID        List();
        virtual T100RESULT      Find(T100WSTRING);

        virtual T100VOID        ShowResult(T100RESULT, T100WSTRING&);

    protected:

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100TEST_H
