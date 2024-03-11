#include "T100Asm64FunctionScanner.h"

T100Asm64FunctionScanner::T100Asm64FunctionScanner()
{
    //ctor
}

T100Asm64FunctionScanner::~T100Asm64FunctionScanner()
{
    //dtor
}

T100VOID T100Asm64FunctionScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64SentenceScanner*>(scanner);
}

T100Scanner* T100Asm64FunctionScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64FunctionScanner::next(T100Token& token)
{
    m_scanner->next(m_item);
}

T100BOOL T100Asm64FunctionScanner::read()
{

}

T100BOOL T100Asm64FunctionScanner::parse()
{

}
