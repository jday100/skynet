#include "T100SegmentScan.h"

#include "T100Sentence.h"


T100SegmentScan::T100SegmentScan()
{
    //ctor
}

T100SegmentScan::~T100SegmentScan()
{
    //dtor
}

T100BOOL T100SegmentScan::open(T100String& file)
{
    m_scan = T100NEW T100SentenceScan();
    return m_scan->open(file);
}

T100BOOL T100SegmentScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100SegmentToken* T100SegmentScan::getToken()
{
    return m_token;
}

T100SentenceToken* T100SegmentScan::getItem()
{
    return &m_item;
}

T100BOOL T100SegmentScan::append()
{
    m_token->sentences.push_back(m_item.copy());

    return T100TRUE;
}

T100BOOL T100SegmentScan::read()
{
    return m_scan->next(m_item);
}

T100BOOL T100SegmentScan::next(IToken& token)
{
    m_token = (T100SegmentToken*)&token;
    m_token->clear();

    return run();
}

T100BOOL T100SegmentScan::run()
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

                    m_token->name   = m_item.data->data;

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

                    T100AssemblyLog::info(T100LOG_SEGMENT, T100AssemblyHint::segment_hint(m_token, ""));
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
