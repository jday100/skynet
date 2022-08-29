#ifndef IORDER_H
#define IORDER_H

#include "T100Common.h"
class IComputer;
class IExecutor;


class IOrder
{
    public:
        IOrder(IComputer*, IExecutor*);
        virtual ~IOrder();

    protected:
        IComputer*          m_host         = T100NULL;
        IExecutor*          m_exec         = T100NULL;

    private:
};

#endif // IORDER_H
