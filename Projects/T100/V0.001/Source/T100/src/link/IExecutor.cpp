#include "IExecutor.h"

IExecutor::IExecutor(IComputer* host)
    :m_host(host)
{
    //ctor
}

IExecutor::~IExecutor()
{
    //dtor
}
