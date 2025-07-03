#include "T100ByteScanner.h"

namespace T100LIBRARY{

T100ByteScanner::T100ByteScanner() :
    T100LeafScanner()
{
    //ctor
}

T100ByteScanner::~T100ByteScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100ByteScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100BufferScanner*>(scanner);
}

T100LeafScanner* T100ByteScanner::GetSource()
{
    return m_scanner;
}

T100VOID T100ByteScanner::SetClassifier(T100ByteClassifier* classifier)
{
    m_classifier    = classifier;
    m_classifier->SetScanner(this);
}

T100ByteClassifier* T100ByteScanner::GetClassifier()
{
    return m_classifier;
}

T100BOOL T100ByteScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100ByteToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    Clear();

    return Run();
}

T100BOOL T100ByteScanner::Read()
{
    T100BOOL        result;

    if(m_loaded){
        result  = T100TRUE;
    }else{
        result  = m_scanner->Next(*m_state, m_item);
    }

    return result;
}

T100BOOL T100ByteScanner::Append()
{

}

T100BOOL T100ByteScanner::Clear()
{
    m_token->Value      = 0;
}

T100BOOL T100ByteScanner::Run()
{
    return m_classifier->Classify();
}

}
