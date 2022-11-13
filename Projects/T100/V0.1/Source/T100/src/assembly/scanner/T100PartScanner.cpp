#include "T100PartScanner.h"

#include "T100SentenceImport.h"


namespace T100Assembly{

T100TOKEN_TYPE      T100PartScanner::m_type                         = T100PART_SOURCE;

T100PartScanner::T100PartScanner()
    :T100Component::T100Scanner()
{
    //ctor
    create();
}

T100PartScanner::~T100PartScanner()
{
    //dtor
    destroy();
}

T100VOID T100PartScanner::create()
{
    m_type = T100PART_SOURCE;
}

T100VOID T100PartScanner::destroy()
{

}

T100VOID T100PartScanner::setSource(T100Component::T100Scanner* scanner)
{
    m_scanner = dynamic_cast<T100SegmentScanner*>(scanner);
}

T100Component::T100Scanner* T100PartScanner::getSource()
{
    return m_scanner;
}

T100PartToken* T100PartScanner::getToken()
{
    return m_token;
}

T100SegmentToken* T100PartScanner::getItem()
{
    return &m_item;
}

T100BOOL T100PartScanner::append()
{
    m_token->segments.push_back(m_item.copy());

    return T100TRUE;
}

T100BOOL T100PartScanner::read()
{
    T100BOOL        result          = T100FALSE;

    result = m_scanner->next(m_item);
    if(result){
        setLoaded(T100TRUE);
    }

    return result;
}

T100BOOL T100PartScanner::next(T100Component::T100Token& token)
{
    m_token = (T100PartToken*)&token;
    m_token->clear();

    m_token->type = T100PART_SOURCE;

    return run();
}

T100BOOL T100PartScanner::run()
{
    T100BOOL        result          = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result)return T100FALSE;
    }

    switch(m_item.type){
    case T100TOKEN_EOF:
        {
            m_token->type           = T100TOKEN_EOF;
            m_token->eof            = m_item.eof;
            m_token->row            = m_item.row;
            return T100TRUE;
        }
        break;
    case T100SEGMENT_IMPORT:
        {
            m_token->type           = T100PART_IMPORT;
            m_token->file           = getFile();
            setLoaded(T100FALSE);
            return T100TRUE;
        }
        break;
    default:
        do{
            if(!isLoaded()){
                result = read();
                if(!result){
                    return T100FALSE;
                }
            }

            switch(m_item.type){
            case T100TOKEN_EOF:
                {
                    return T100TRUE;
                }
                break;
            default:
                append();
                setLoaded(T100FALSE);
            };
        }while(T100TRUE);
    };

    return result;
}

T100STRING T100PartScanner::getFile()
{
    T100STRING      result;

    if(1 == m_item.sentences.size()){
        T100SentenceToken*  token = m_item.sentences[0];

        if(T100SENTENCE_IMPORT == token->type){
            T100SentenceImport*  data = (T100SentenceImport*)(token->value);

            result = data->file;
        }
    }

    return result;
}

}
