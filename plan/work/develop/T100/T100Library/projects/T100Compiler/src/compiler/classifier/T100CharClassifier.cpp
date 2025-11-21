#include "T100CharClassifier.h"

#include "common/T100BitCommon.h"
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
    T100BOOL            result      = T100TRUE;

    T100WCHAR           value;

    value   = m_scanner->m_token->Value;

    if(value >= T100ASCII_ZERO && value <= T100ASCII_NINE){
        m_scanner->m_token->Type    = T100CHAR_DIGIT;
    }else if(value >= T100ASCII_UPPER_A && value <= T100ASCII_UPPER_Z){
        m_scanner->m_token->Type    = T100CHAR_UPPER;
    }else if(value >= T100ASCII_LOWER_A && value <= T100ASCII_LOWER_Z){
        m_scanner->m_token->Type    = T100CHAR_LOWER;
    }else{
        m_scanner->m_token->Type    = T100CHAR_UNICODE;
    }

    return result;
}

}
