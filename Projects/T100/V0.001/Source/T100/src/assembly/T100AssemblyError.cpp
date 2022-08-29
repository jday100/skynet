#include "T100AssemblyError.h"

T100BOOL        T100AssemblyError::detail   = T100FALSE;


T100AssemblyError::T100AssemblyError()
{
    //ctor
}

T100AssemblyError::~T100AssemblyError()
{
    //dtor
}

T100BOOL T100AssemblyError::push()
{
    return T100FALSE;
}

T100BOOL T100AssemblyError::pop()
{
    return T100FALSE;
}

T100BOOL T100AssemblyError::print()
{
    return T100FALSE;
}
