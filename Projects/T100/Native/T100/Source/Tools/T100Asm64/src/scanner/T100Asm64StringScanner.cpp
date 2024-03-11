#include "T100Asm64StringScanner.h"

#include "T100Log.h"

T100Asm64StringScanner::T100Asm64StringScanner()
{
    //ctor
}

T100Asm64StringScanner::~T100Asm64StringScanner()
{
    //dtor
}

T100VOID T100Asm64StringScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64LetterScanner*>(scanner);
}

T100Scanner* T100Asm64StringScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64StringScanner::next(T100Token& token)
{
    while(m_scanner->next(m_item)){
        T100STRING      value;

        value   = m_item.value;
        T100Log::log(value);
    }
}

T100BOOL T100Asm64StringScanner::read()
{

}

T100BOOL T100Asm64StringScanner::append()
{

}

T100VOID T100Asm64StringScanner::clear()
{

}

T100BOOL T100Asm64StringScanner::classify()
{

}

T100BOOL T100Asm64StringScanner::isOperator()
{

}
