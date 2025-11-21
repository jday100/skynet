#include "T100ByteClassifier.h"

#include "common/T100BitCommon.h"
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
    T100BOOL            result      = T100TRUE;
    T100BYTE_BIT        value;

    value.BYTE      = m_scanner->m_item.Value;

    if(value.BIT7){
        if(value.BIT6){
            if(value.BIT5){
                if(value.BIT4){
                    if(value.BIT3){
                        if(value.BIT2){
                            if(value.BIT1){
                                if(value.BIT0){
                                    m_scanner->m_token->Type    = T100BYTE_EIGHT;
                                }else{
                                    m_scanner->m_token->Type    = T100BYTE_SEVEN;
                                }
                            }else{
                                m_scanner->m_token->Type    = T100BYTE_SIX;
                            }
                        }else{
                            m_scanner->m_token->Type    = T100BYTE_FIVE;
                        }
                    }else{
                        m_scanner->m_token->Type    = T100BYTE_FOUR;
                    }
                }else{
                    m_scanner->m_token->Type    = T100BYTE_THREE;
                }
            }else{
                m_scanner->m_token->Type    = T100BYTE_TWO;
            }
        }else{
            m_scanner->m_token->Type    = T100BYTE_ONE;
        }
    }else{
        m_scanner->m_token->Type    = T100BYTE_ASCII;
    }

    if(result){
        m_scanner->m_token->Value   = value.BYTE;
    }

    return result;
}

}
