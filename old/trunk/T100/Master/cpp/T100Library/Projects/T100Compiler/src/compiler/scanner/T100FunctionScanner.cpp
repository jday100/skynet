#include "T100FunctionScanner.h"

namespace T100LIBRARY{

T100FunctionScanner::T100FunctionScanner() :
    T100LeafScanner()
{
    //ctor
}

T100FunctionScanner::~T100FunctionScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner)
}

T100VOID T100FunctionScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100SegmentScanner*>(scanner);
}

T100LeafScanner* T100FunctionScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100FunctionScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100FunctionToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100FunctionScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
