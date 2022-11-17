#include "T100Assembly.h"

namespace T100Assembly{

T100Assembly::T100Assembly()
{
    //ctor
}

T100Assembly::~T100Assembly()
{
    //dtor
}

T100Produce& T100Assembly::getProduce()
{
    return m_produce;
}

T100BOOL T100Assembly::run(T100STRING source, T100STRING target)
{
    return m_produce.run(source, target);
}

}
