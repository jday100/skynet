#ifndef T100ORDER_H
#define T100ORDER_H

#include "T100VPCCommon.h"
#include "IOrder.h"
#include "T100OrderTypes.h"
#include "T100QU32.h"


/*
load
TWO                                 SIX
loadTarget                          loadTarget
    loadOperator                        loadOperator            loadOperator
        loadRegister                        loadRegister            loadRegister
        loadMemory                          loadMemory              loadMemory

loadSource                          loadSource
    loadOperator                        loadOperator            loadOperator
        loadRegister                        loadRegister            loadRegister
        loadMemory                          loadMemory              loadMemory

getSource                           getComplexusSource
    getOperator                         getComplexus
        getRegister                         getOperator             getOperator
        getMemory                               getRegister             getRegister
                                                getMemory               getMemory

setTarget                           setComplexusTarget
    setRegister
    setMemory                           setMemory
*/

/*
load
TWO                     SIX
loadTarget              loadTarget
    loadOperator            loadOperator        loadOperator
        loadRegister            loadRegister        loadRegister
        loadMemory              loadMemory          loadMemory
loadSource              loadSource
    loadOperator            loadOperator        loadOperator
        loadRegister            loadRegister        loadRegister
        loadMemory              loadMemory          loadMemory
getSource               getSource
        getOperator         get
            getRegister         getOperator         getOperator
            getMemory               getRegister         getRegister
                                    getMemory           getMemory
setTarget               setTarget
    setRegister
    setMemory               setMemory
*/


class T100Order : private IOrder
{
    public:
        T100Order(T100QU32*, T100Executor32*);
        virtual ~T100Order();

        T100BOOL                execute(T100WORD);

        T100BOOL                execute_log(T100WORD);
        T100BOOL                execute_none(T100WORD);

    protected:
        T100WORD                m_order;
        T100WORD                m_type      = 0;

        T100WORD                m_base;
        T100WORD                m_offset;

        virtual T100BOOL        run()=0;
        virtual T100VOID        log()=0;

        T100QU32*               getHost();
        T100Executor32*         getExecutor();


        //
        T100BOOL                parse(T100OPERATOR_DOUBLE&, T100OPERATOR_DOUBLE&);

    protected:
        T100BOOL                load(T100OPERATOR_DOUBLE&, T100OPERATOR_DOUBLE&);

        T100BOOL                loadTarget(T100OPERATOR_DOUBLE&);
        T100BOOL                loadSource(T100OPERATOR_DOUBLE&);

        T100BOOL                loadMonoTarget(T100OPERATOR_DOUBLE&);

        T100BOOL                loadOperator(T100OPERATOR_SINGLE&);
        T100BOOL                loadRegister(T100OPERATOR_SINGLE&);
        T100BOOL                loadMemory(T100OPERATOR_SINGLE&);

        T100BOOL                getSource(T100OPERATOR_DOUBLE&, T100WORD&);
        T100BOOL                getComplexusSource(T100OPERATOR_DOUBLE&, T100WORD&);
        T100BOOL                getIOSource(T100OPERATOR_DOUBLE&, T100WORD&);

        T100BOOL                setTarget(T100OPERATOR_DOUBLE&, T100WORD);
        T100BOOL                setIOTarget(T100OPERATOR_DOUBLE&, T100WORD);

        T100BOOL                setOperator(T100OPERATOR_SINGLE&, T100WORD);

        T100BOOL                setRegister(T100OPERATOR_SINGLE&, T100WORD);
        T100BOOL                setMemory(T100OPERATOR_SINGLE&, T100WORD);


};

#endif // T100ORDER_H
