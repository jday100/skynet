#include "T100CapacityScanner.h"

namespace T100Library{

T100CapacityScanner::T100CapacityScanner()
    :T100Component::T100Scanner()
{
    //ctor
}

T100CapacityScanner::~T100CapacityScanner()
{
    //dtor
}

T100VOID T100CapacityScanner::create()
{

}

T100VOID T100CapacityScanner::destroy()
{

}

T100VOID T100CapacityScanner::setSource(T100CapacityCharScanner* scanner)
{
    m_scanner = scanner;
}

T100CapacityCharScanner* T100CapacityScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100CapacityScanner::next(T100Component::T100Token& token)
{

}

}
