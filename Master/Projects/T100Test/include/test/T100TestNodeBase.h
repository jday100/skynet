#ifndef T100TESTNODEBASE_H
#define T100TESTNODEBASE_H

#include <atomic>
#include "base/T100Result.h"
#include "console/T100Console.h"
#include "object/T100ObjectTreeNode.h"

class T100TestNodeBase : public T100ObjectTreeNode
{
    public:
        T100TestNodeBase(T100WSTRING, T100TestNodeBase*);
        virtual ~T100TestNodeBase();

        T100INT                     Argc;
        T100WCHAR**                 Argv;

    protected:
        T100TestNodeBase*           ConvertNode(T100ObjectTreeNode*);
        T100Console*                GetConsole();

        virtual T100RESULT          DoGlobalInit();
        virtual T100RESULT          DoGlobalUninit();

        virtual T100RESULT          GlobalInit();
        virtual T100RESULT          GlobalUninit();

        virtual T100RESULT          DoInit();
        virtual T100RESULT          DoUninit();

        virtual T100RESULT          Init();
        virtual T100RESULT          Uninit();

        virtual T100RESULT          DoTest();

        virtual T100VOID            SetIndex();
        virtual T100VOID            SetSuccess();
        virtual T100VOID            SetFailure();
        virtual T100VOID            SetException();

        virtual T100VOID            Insert();
        virtual T100VOID            Append();
        virtual T100VOID            Remove();

        virtual T100VOID            Out(T100WSTRING);
        virtual T100VOID            OutTestBegin(T100WSTRING&);
        virtual T100VOID            OutTestEnd(T100RESULT, T100WSTRING&);

    protected:
        std::atomic_bool            m_globalInited;
        std::atomic_bool            m_globalUninited;

        std::atomic_bool            m_needGlobalInit;
        std::atomic_bool            m_needGlobalUninit;

        std::atomic_bool            m_unitInited;
        std::atomic_bool            m_unitUninited;

        std::atomic_bool            m_needUnitInit;
        std::atomic_bool            m_needUnitUninit;

        T100WORD                    m_countUnits        = 0;
        T100WORD                    m_index             = 0;
        T100WORD                    m_countSuccess      = 0;
        T100WORD                    m_countFailure      = 0;
        T100WORD                    m_countException    = 0;

    private:
        T100Console*                m_consolePtr        = T100NULL;

        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100TESTNODEBASE_H
