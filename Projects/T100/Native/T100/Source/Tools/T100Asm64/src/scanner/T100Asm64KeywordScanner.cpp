#include "T100Asm64KeywordScanner.h"

T100Asm64KeywordScanner::T100Asm64KeywordScanner()
{
    //ctor
}

T100Asm64KeywordScanner::~T100Asm64KeywordScanner()
{
    //dtor
}

T100VOID T100Asm64KeywordScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64StringScanner*>(scanner);
}

T100Scanner* T100Asm64KeywordScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64KeywordScanner::next(T100Token& token)
{
    m_scanner->next(m_item);
}

T100BOOL T100Asm64KeywordScanner::append()
{

}

T100BOOL T100Asm64KeywordScanner::classify()
{

}
