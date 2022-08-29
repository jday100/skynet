#include "T100TestHelp.h"

T100STDSTRING       T100TestHelp::m_unit        = "help";


T100TestHelp::T100TestHelp()
    :T100Test(m_unit)
{
    //ctor
}

T100TestHelp::~T100TestHelp()
{
    //dtor
}

T100BOOL T100TestHelp::test_all()
{
    return T100FALSE;
}
