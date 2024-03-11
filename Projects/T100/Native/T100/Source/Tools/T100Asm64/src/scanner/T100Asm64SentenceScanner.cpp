#include "T100Asm64SentenceScanner.h"

T100Asm64SentenceScanner::T100Asm64SentenceScanner()
{
    //ctor
}

T100Asm64SentenceScanner::~T100Asm64SentenceScanner()
{
    //dtor
}

T100Asm64SentenceToken* T100Asm64SentenceScanner::getToken()
{

}

T100Asm64KeywordToken* T100Asm64SentenceScanner::getItem()
{

}

T100VOID T100Asm64SentenceScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64KeywordScanner*>(scanner);
}

T100Scanner* T100Asm64SentenceScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64SentenceScanner::next(T100Token& token)
{
    m_scanner->next(m_item);
}

T100BOOL T100Asm64SentenceScanner::read()
{

}

T100BOOL T100Asm64SentenceScanner::append()
{

}

T100BOOL T100Asm64SentenceScanner::parse()
{

}
