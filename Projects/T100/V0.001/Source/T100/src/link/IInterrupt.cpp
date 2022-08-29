#include "IInterrupt.h"

IInterrupt::IInterrupt(IComputer* host)
    :m_host(host)
{
    //ctor
}

IInterrupt::~IInterrupt()
{
    //dtor
}
