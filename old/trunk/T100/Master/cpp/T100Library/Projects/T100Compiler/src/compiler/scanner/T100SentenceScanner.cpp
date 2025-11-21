#include "T100SentenceScanner.h"

namespace T100LIBRARY{

T100SentenceScanner::T100SentenceScanner() :
    T100LeafScanner()
{
    //ctor
}

T100SentenceScanner::~T100SentenceScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100SentenceScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100KeywordScanner*>(scanner);
}

T100LeafScanner* T100SentenceScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100SentenceScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100SentenceToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100SentenceScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
