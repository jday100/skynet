#include "T100KeywordScanner.h"

namespace T100LIBRARY{

T100KeywordScanner::T100KeywordScanner() :
    T100LeafScanner()
{
    //ctor
}

T100KeywordScanner::~T100KeywordScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100KeywordScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100StringScanner*>(scanner);
}

T100LeafScanner* T100KeywordScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100KeywordScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100KeywordToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100KeywordScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
