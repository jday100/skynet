#include "T100CharScanner.h"

namespace T100LIBRARY{

T100CharScanner::T100CharScanner() :
    T100LeafScanner()
{
    //ctor
}

T100CharScanner::~T100CharScanner()
{
    //dtor
    T100SAFE_DELETE(m_scanner);
}

T100VOID T100CharScanner::SetSource(T100LeafScanner* scanner)
{
    m_scanner       = dynamic_cast<T100ByteScanner*>(scanner);
}

T100LeafScanner* T100CharScanner::GetSource()
{
    return m_scanner;
}

T100VOID T100CharScanner::SetClassifier(T100CharClassifier* classifier)
{
    m_classifier    = classifier;
}

T100CharClassifier* T100CharScanner::GetClassifier()
{
    return m_classifier;
}

T100BOOL T100CharScanner::Read()
{
    T100BOOL        result;

    if(m_loaded){
        result  = T100TRUE;
    }else{
        result  = m_scanner->Next(*m_state, m_item);
    }

    return result;
}

T100BOOL T100CharScanner::Append()
{
    m_token->Value      = m_item.Value;
    return T100TRUE;
}

T100BOOL T100CharScanner::Clear()
{
    m_token->Value      = 0;
}

T100BOOL T100CharScanner::Next(T100LeafState& state, T100LeafToken& token)
{
    m_state     = &state;
    m_token     = dynamic_cast<T100CharToken*>(&token);

    if(!m_token){
        return T100FALSE;
    }

    Clear();

    return Run();
}

T100BOOL T100CharScanner::Run()
{
    T100BOOL        result;

    result  = Read();

    if(!result){
        return T100FALSE;
    }

    switch(m_item.Type){
    case T100BYTE_ASCII:
        {
            result  = Append();
        }
        break;
    case T100BYTE_ONE:
        {

        }
        break;
    case T100BYTE_TWO:
        {

        }
        break;
    case T100BYTE_THREE:
        {

        }
        break;
    case T100BYTE_FOUR:
        {

        }
        break;
    }

    if(result){
        result  = m_classifier->Classify();
    }

    return result;
}

}
