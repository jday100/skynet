#ifndef T100TEST_H
#define T100TEST_H

#include <atomic>
#include "vessel/T100Vessel.h"
#include "object/T100ObjectTree.h"
#include "log/T100Logger.h"
//#include "console/T100Console.h"

#define     T100TEST_VESSEL         T100Vessel<T100WSTRING, T100Test*>

class T100Test : public T100ObjectTree
{
    public:
        T100Test(T100Test*, T100WSTRING name = L"all");
        virtual ~T100Test();

        T100INT                 Argc;
        T100WCHAR**             Argv;

        T100VOID                SetGlobalInit(T100BOOL);
        T100VOID                SetGlobalUninit(T100BOOL);

        T100VOID                SetInit(T100BOOL);
        T100VOID                SetUninit(T100BOOL);

        virtual T100BOOL        TestAll();
        virtual T100BOOL        TestUnit(T100WSTRING);

        virtual T100VOID        List();
        virtual T100BOOL        Find(T100WSTRING);

        virtual T100VOID        ShowResult(T100BOOL, T100WSTRING&);

    protected:
        virtual T100BOOL        DoInit();
        virtual T100BOOL        DoUninit();

        virtual T100BOOL        Init();
        virtual T100BOOL        Uninit();

        virtual T100BOOL        DoGlobalInit();
        virtual T100BOOL        DoGlobalUninit();

        virtual T100BOOL        GlobalInit();
        virtual T100BOOL        GlobalUninit();

        virtual T100VOID        Index();
        virtual T100VOID        Success();
        virtual T100VOID        Failure();

    protected:
        virtual T100VOID        Create();
        virtual T100VOID        Destroy();

        virtual T100VOID        Add();
        virtual T100BOOL        DoTest();

        virtual T100VOID        Out(T100WSTRING);
        virtual T100VOID        OutTestBegin(T100WSTRING&);
        virtual T100VOID        OutTestEnd(T100BOOL, T100WSTRING&);
        virtual T100VOID        OutList(T100WSTRING&);
        virtual T100VOID        OutListBegin();
        virtual T100VOID        OutListEnd();

        virtual T100VOID        Insert(T100WSTRING, T100Test*);
        virtual T100VOID        Append(T100WSTRING, T100Test*);
        virtual T100VOID        Remove(T100WSTRING);

    private:
        std::atomic_bool        m_globalInited;
        std::atomic_bool        m_globalUninited;

        std::atomic_bool        m_unitInited;
        std::atomic_bool        m_unitUninited;

        std::atomic_bool        m_needGlobalInit;
        std::atomic_bool        m_needGlobalUninit;

        std::atomic_bool        m_needUnitInit;
        std::atomic_bool        m_needUnitUninit;

        T100WSTRING             m_name;

        T100WORD                m_units         = 0;
        T100WORD                m_index         = 0;
        T100WORD                m_success       = 0;
        T100WORD                m_failure       = 0;

        T100TEST_VESSEL         m_tests;
};

#endif // T100TEST_H
