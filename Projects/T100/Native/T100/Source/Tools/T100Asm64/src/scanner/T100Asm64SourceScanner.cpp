#include "T100Asm64SourceScanner.h"

#include "T100Log.h"

T100Asm64SourceScanner::T100Asm64SourceScanner()
    :T100Scanner()
{
    //ctor
}

T100Asm64SourceScanner::~T100Asm64SourceScanner()
{
    //dtor
}

T100VOID T100Asm64SourceScanner::setSource(T100Scanner* scanner)
{
    m_scanner   = dynamic_cast<T100Asm64FunctionScanner*>(scanner);
}

T100Scanner* T100Asm64SourceScanner::getSource()
{
    return m_scanner;
}

T100BOOL T100Asm64SourceScanner::next(T100Token& token)
{
    while(m_scanner->next(m_item)){
        //T100Log::log(m_item.);
    }
}

T100BOOL T100Asm64SourceScanner::append()
{

}

T100BOOL T100Asm64SourceScanner::classify()
{

}
