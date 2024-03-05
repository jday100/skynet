#include "T100Scanner.h"

T100Scanner::T100Scanner()
{
    //ctor
    m_loaded    = T100FALSE;
}

T100Scanner::~T100Scanner()
{
    //dtor
}

T100BOOL T100Scanner::read()
{
    return T100FALSE;
}

T100BOOL T100Scanner::append()
{
    return T100FALSE;
}

T100VOID T100Scanner::clear()
{

}

T100VOID T100Scanner::setLoaded(T100BOOL value)
{
    m_loaded    = value;
}

T100BOOL T100Scanner::isLoaded()
{
    return m_loaded;
}
