#ifndef T100TESTBASE_H
#define T100TESTBASE_H

#include <atomic>
#include "object/T100Tree.h"
#include "vessel/T100Vessel.h"
#include "console/T100Console.h"

namespace T100LIBRARY{

class T100TestBase : public T100Tree
{
    public:
        T100TestBase();
        virtual ~T100TestBase();

        T100VOID                    SetNeedGlobalInit(T100BOOL);
        T100BOOL                    IsNeedGlobalInit();

        T100VOID                    SetNeedGlobalUninit(T100BOOL);
        T100BOOL                    IsNeedGlobalUninit();

        T100VOID                    SetNeedInit(T100BOOL);
        T100BOOL                    IsNeedInit();

        T100VOID                    SetNeedUninit(T100BOOL);
        T100BOOL                    IsNeedUninit();

    protected:
        virtual T100BOOL            doInit();
        virtual T100BOOL            doUninit();

        virtual T100BOOL            init();
        virtual T100BOOL            uninit();

        virtual T100BOOL            doGlobalInit();
        virtual T100BOOL            doGlobalUninit();

        virtual T100BOOL            globalInit();
        virtual T100BOOL            globalUninit();

        virtual T100VOID            doIndex();
        virtual T100VOID            doSuccess();
        virtual T100VOID            doFailure();
        virtual T100VOID            doException();

        virtual T100BOOL            DoTest();

    protected:
        virtual T100Console*        getConsole();

        virtual T100VOID            out(const T100WSTRING&);
        virtual T100VOID            outTestBegin(const T100WSTRING&);
        virtual T100VOID            outTestEnd(T100BOOL, const T100WSTRING&);
        virtual T100VOID            outList(const T100WSTRING&);
        virtual T100VOID            outListBegin();
        virtual T100VOID            outListEnd();

    protected:
        std::atomic_bool            m_globalInited;
        std::atomic_bool            m_globalUninited;

        std::atomic_bool            m_unitInited;
        std::atomic_bool            m_unitUninited;

        std::atomic_bool            m_needGlobalInit;
        std::atomic_bool            m_needGlobalUninit;

        std::atomic_bool            m_needUnitInit;
        std::atomic_bool            m_needUnitUninit;

        T100Console*                m_console           = T100NULL;

        T100UINT                    m_units             = 0;
        T100UINT                    m_index             = 0;
        T100UINT                    m_success           = 0;
        T100UINT                    m_failure           = 0;
        T100UINT                    m_exception         = 0;

    private:
};

}

#endif // T100TESTBASE_H
