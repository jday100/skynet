#include "T100CapacityCharScanner.h"

namespace T100Library{

T100CapacityCharScanner::T100CapacityCharScanner()
    :T100Component::T100Scanner()
{
    //ctor
}

T100CapacityCharScanner::~T100CapacityCharScanner()
{
    //dtor
}

T100VOID T100CapacityCharScanner::setSource(T100WSTRING str)
{
    m_string    = str;
    m_index     = 0;
}

T100BOOL T100CapacityCharScanner::next(T100Component::T100Token& token)
{

}

}
