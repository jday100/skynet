#include "T100SegmentScanner.h"

namespace T100LIBRARY{

T100SegmentScanner::T100SegmentScanner() :
    T100LeafScanner()
{
    //ctor
}

T100SegmentScanner::~T100SegmentScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100SegmentScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100SentenceScanner*>(scanner);
}

T100LeafScanner* T100SegmentScanner::GetSource()
{
    return m_scanner;
}

T100BOOL T100SegmentScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100SegmentToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    return Run();
}

T100BOOL T100SegmentScanner::Run()
{
    return m_scanner->Next(*m_state, m_item);
}

}
