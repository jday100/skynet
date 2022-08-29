#include "T100SegmentScanner.h"

#include "T100Sentence.h"


T100SegmentScanner::T100SegmentScanner()
{
    //ctor
}

T100SegmentScanner::~T100SegmentScanner()
{
    //dtor
}

T100VOID T100SegmentScanner::setSource(T100Scanner* scanner)
{
    m_scanner = dynamic_cast<T100SentenceScanner*>(scanner);
}

T100Scanner* T100SegmentScanner::getSource()
{
    return m_scanner;
}

T100SegmentToken* T100SegmentScanner::getToken()
{
    return m_token;
}

T100SentenceToken* T100SegmentScanner::getItem()
{
    return &m_item;
}

T100BOOL T100SegmentScanner::append()
{
    m_token->sentences.push_back(m_item.copy());

    return T100TRUE;
}

T100BOOL T100SegmentScanner::read()
{
    return m_scanner->next(m_item);
}

T100BOOL T100SegmentScanner::next(T100Token& token)
{
    m_token = (T100SegmentToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100SegmentScanner::run()
{
    T100BOOL    result      = T100FALSE;

    do{
        result = read();
        if(!result){
            return T100FALSE;
        }

        switch(m_item.type){
            case T100SENTENCE_MODE:
                {
                    m_token->type   = T100SEGMENT_MODE;
                    append();
                    return T100TRUE;
                    break;
                }
            case T100SENTENCE_IMPORT:
                {
                    m_token->type   = T100SEGMENT_IMPORT;
                    append();
                    return T100TRUE;
                    break;
                }
            case T100SENTENCE_CODE:
                {
                    m_token->type   = T100SEGMENT_CODE;

                    m_token->name   = m_item.value->value;

                    append();
                    break;
                }
            case T100SENTENCE_DATA:
                {
                    m_token->type   = T100SEGMENT_DATA;
                    append();
                    break;
                }
            case T100SENTENCE_PROCEDURE:
                {
                    m_token->type   = T100SEGMENT_PROCEDURE;
                    append();
                    break;
                }
            case T100SENTENCE_END:
                {
                    append();

                    //T100AssemblyLog::info(T100LOG_SEGMENT, T100AssemblyHint::segment_hint(m_token, ""));
                    return T100TRUE;
                    break;
                }
            case T100TOKEN_EOF:
                {
                    m_token->type   = T100TOKEN_EOF;
                    m_token->eof    = T100TRUE;
                    m_token->row    = m_item.row;
                    return T100TRUE;
                    break;
                }
            default:
                append();
                break;
        };

    }while(T100TRUE);

    return T100FALSE;
}
