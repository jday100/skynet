#include "T100SourceScanner.h"

namespace T100LIBRARY{

T100SourceScanner::T100SourceScanner() :
    T100LeafScanner()
{
    //ctor
}

T100SourceScanner::~T100SourceScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100SourceScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100FunctionScanner*>(scanner);
}

T100LeafScanner* T100SourceScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100SourceScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100SourceToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100SourceScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
