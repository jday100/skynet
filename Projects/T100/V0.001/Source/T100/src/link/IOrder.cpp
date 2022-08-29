#include "IOrder.h"

IOrder::IOrder(IComputer* host, IExecutor* exec)
    :m_host(host),m_exec(exec)
{
    //ctor
}

IOrder::~IOrder()
{
    //dtor
}
