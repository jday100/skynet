#include "T100Scanner.h"

T100Scanner::T100Scanner()
{
    //ctor
    create();
}

T100Scanner::~T100Scanner()
{
    //dtor
    destroy();
}

T100VOID T100Scanner::create()
{
    m_loaded = T100FALSE;
}

T100VOID T100Scanner::destroy()
{

}

T100VOID T100Scanner::clear()
{
    m_loaded = T100FALSE;
}

T100BOOL T100Scanner::read()
{
    return T100FALSE;
}

T100BOOL T100Scanner::append()
{
    return T100FALSE;
}

T100VOID T100Scanner::setLoaded(T100BOOL flag)
{
    m_loaded = flag;
}

T100BOOL T100Scanner::isLoaded()
{
    return m_loaded;
}
