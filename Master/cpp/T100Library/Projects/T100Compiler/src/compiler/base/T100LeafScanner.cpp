#include "T100LeafScanner.h"

namespace T100LIBRARY{

T100LeafScanner::T100LeafScanner() :
    T100Scanner()
{
    //ctor
    init();
}

T100LeafScanner::~T100LeafScanner()
{
    //dtor
    uninit();
}

T100VOID T100LeafScanner::init()
{
    m_loaded    = T100FALSE;
}

T100VOID T100LeafScanner::uninit()
{

}

T100VOID T100LeafScanner::SetLoaded(T100BOOL flag)
{
    m_loaded    = flag;
}

T100BOOL T100LeafScanner::IsLoaded()
{
    return m_loaded;
}

T100BOOL T100LeafScanner::Read()
{
    return T100FALSE;
}

T100BOOL T100LeafScanner::Append()
{
    return T100FALSE;
}

T100BOOL T100LeafScanner::Clear()
{
    return T100FALSE;
}

}
