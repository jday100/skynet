#include "T100StringScanner.h"

namespace T100LIBRARY{

T100StringScanner::T100StringScanner() :
    T100LeafScanner()
{
    //ctor
}

T100StringScanner::~T100StringScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100StringScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100CharScanner*>(scanner);
}

T100LeafScanner* T100StringScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100StringScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100StringToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100StringScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
