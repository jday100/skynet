#include "T100CharClassifier.h"

#include "compiler/scanner/T100CharScanner.h"

namespace T100LIBRARY{

T100CharClassifier::T100CharClassifier() :
    T100Classifier()
{
    //ctor
}

T100CharClassifier::~T100CharClassifier()
{
    //dtor
}

T100VOID T100CharClassifier::SetScanner(T100CharScanner* scanner)
{
    m_scanner       = scanner;
}

T100CharScanner* T100CharClassifier::GetScanner()
{
    return m_scanner;
}

T100BOOL T100CharClassifier::Classify()
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
