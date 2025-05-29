#ifndef T100TESTBASE_H
#define T100TESTBASE_H

#include <atomic>
#include "vessel/T100Vessel.h"
#include "object/T100ObjectTreeNode.h"
#include "log/T100Logger.h"
#include "console/T100Console.h"

#include "base/T100Result.h"

class T100Test;

#define     T100TEST_VESSEL         T100Vessel<T100WSTRING, T100Test*>

class T100TestBase : public T100ObjectTreeNode
{
    public:
        T100TestBase(T100TestBase*, T100WSTRING name);
        virtual ~T100TestBase();

        T100INT                 Argc;
        T100WCHAR**             Argv;

    protected:
        virtual T100RESULT      DoInit();
        virtual T100RESULT      DoUninit();

        virtual T100RESULT      Init();
        virtual T100RESULT      Uninit();

        virtual T100RESULT      DoGlobalInit();
        virtual T100RESULT      DoGlobalUninit();

        virtual T100RESULT      GlobalInit();
        virtual T100RESULT      GlobalUninit();

        virtual T100VOID        Index();
        virtual T100VOID        Success();
        virtual T100VOID        Failure();

    protected:
        virtual T100Console*    GetConsole();

        virtual T100VOID        Add();
        virtual T100RESULT      DoTest();

        virtual T100VOID        Out(T100WSTRING);
        virtual T100VOID        OutTestBegin(T100WSTRING&);
        virtual T100VOID        OutTestEnd(T100BOOL, T100WSTRING&);
        virtual T100VOID        OutList(T100WSTRING&);
        virtual T100VOID        OutListBegin();
        virtual T100VOID        OutListEnd();

        virtual T100VOID        Insert(T100WSTRING, T100Test*);
        virtual T100VOID        Append(T100WSTRING, T100Test*);
        virtual T100VOID        Remove(T100WSTRING);

    protected:
        std::atomic_bool        m_globalInited;
        std::atomic_bool        m_globalUninited;

        std::atomic_bool        m_unitInited;
        std::atomic_bool        m_unitUninited;

        std::atomic_bool        m_needGlobalInit;
        std::atomic_bool        m_needGlobalUninit;

        std::atomic_bool        m_needUnitInit;
        std::atomic_bool        m_needUnitUninit;

        T100Console*            m_console       = T100NULL;
        T100Test*               m_parent        = T100NULL;
        T100WSTRING             m_name;

        T100WORD                m_units         = 0;
        T100WORD                m_index         = 0;
        T100WORD                m_success       = 0;
        T100WORD                m_failure       = 0;

        T100TEST_VESSEL         m_tests;

    private:
};

#endif // T100TESTBASE_H
