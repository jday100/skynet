#include "T100Assembly.h"

#include "T100Produce.h"


T100Assembly::T100Assembly()
{
    //ctor
}

T100Assembly::~T100Assembly()
{
    //dtor
}

T100BOOL T100Assembly::run(T100WSTRING& source, T100WSTRING& target)
{
    T100BOOL                result;
    T100Produce             produce;

    T100String              s(source);
    T100String              t(target);

    result = produce.run(s, t);

    return result;
}
