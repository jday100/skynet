#include "T100ByteClassifier.h"

#include "compiler/scanner/T100ByteScanner.h"

namespace T100LIBRARY{

T100ByteClassifier::T100ByteClassifier() :
    T100Classifier()
{
    //ctor
}

T100ByteClassifier::~T100ByteClassifier()
{
    //dtor
}

T100VOID T100ByteClassifier::SetScanner(T100ByteScanner* scanner)
{
    m_scanner       = scanner;
}

T100ByteScanner* T100ByteClassifier::GetScanner()
{
    return m_scanner;
}

T100BOOL T100ByteClassifier::Classify()
{
    T100BOOL        result;

    result  = m_scanner->Read();

    if(result){
        m_scanner->m_token->Value   = 50;

        m_scanner->m_token->Value   = m_scanner->m_item.Value;
    }

    return result;
}

}
