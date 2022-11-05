#ifndef T100ORDER_H
#define T100ORDER_H

#include "T100OrderTypes.h"
#include "T100QU32Common.h"
#include "T100QU32.h"

namespace T100QU32{

class T100Order
{
    public:
        T100Order(T100QU32*, T100Executor32*);
        virtual ~T100Order();

        T100BOOL                    execute(T100WORD);

    protected:
        virtual T100BOOL            run() = 0;
        virtual T100VOID            log() = 0;

        T100WORD                    m_order;
        T100WORD                    m_type          = 0;

        T100WORD                    m_base;
        T100WORD                    m_offset;

        T100QU32*                   getHost();
        T100Executor32*             getExecutor();

        T100BOOL                    parse(T100Component::T100OPERATOR_DOUBLE&, T100Component::T100OPERATOR_DOUBLE&);

    protected:
        T100BOOL                    load(T100Component::T100OPERATOR_DOUBLE&, T100Component::T100OPERATOR_DOUBLE&);

        T100BOOL                    loadTarget(T100Component::T100OPERATOR_DOUBLE&);
        T100BOOL                    loadSource(T100Component::T100OPERATOR_DOUBLE&);

        T100BOOL                    loadMonoTarget(T100Component::T100OPERATOR_DOUBLE&);

        T100BOOL                    loadOperator(T100Component::T100OPERATOR_SINGLE&);
        T100BOOL                    loadRegister(T100Component::T100OPERATOR_SINGLE&);
        T100BOOL                    loadMemory(T100Component::T100OPERATOR_SINGLE&);

        T100BOOL                    getSource(T100Component::T100OPERATOR_DOUBLE&, T100WORD&);
        T100BOOL                    getComplexusSource(T100Component::T100OPERATOR_DOUBLE&, T100WORD&);
        T100BOOL                    getIOSource(T100Component::T100OPERATOR_DOUBLE&, T100WORD&);

        T100BOOL                    setTarget(T100Component::T100OPERATOR_DOUBLE&, T100WORD);
        T100BOOL                    setIOTarget(T100Component::T100OPERATOR_DOUBLE&, T100WORD);

        T100BOOL                    setOperator(T100Component::T100OPERATOR_SINGLE&, T100WORD);

        T100BOOL                    setRegister(T100Component::T100OPERATOR_SINGLE&, T100WORD);
        T100BOOL                    setMemory(T100Component::T100OPERATOR_SINGLE&, T100WORD);

    private:
        T100QU32*                   m_host          = T100NULL;
        T100Executor32*             m_exec          = T100NULL;

};

}

#endif // T100ORDER_H
