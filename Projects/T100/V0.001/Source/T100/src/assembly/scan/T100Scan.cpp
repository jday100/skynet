#include "T100Scan.h"

T100Scan::T100Scan()
{
    //ctor
}

T100Scan::~T100Scan()
{
    //dtor
}

T100VOID T100Scan::clear()
{

}

T100BOOL T100Scan::read()
{
    T100BOOL    result      = T100FALSE;

    return result;
}

T100BOOL T100Scan::append()
{
    T100BOOL    result      = T100FALSE;

    return result;
}

T100VOID T100Scan::setLoaded(T100BOOL value)
{
    m_loaded = value;
}

T100BOOL T100Scan::isLoaded()
{
    return m_loaded;
}
