#include "T100FileScan.h"

#include "T100SentenceImport.h"


T100FileScan::T100FileScan()
{
    //ctor
}

T100FileScan::~T100FileScan()
{
    //dtor
}

T100BOOL T100FileScan::open(T100String& file)
{
    m_scan = T100NEW T100SegmentScan();
    return m_scan->open(file);
}

T100BOOL T100FileScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100FileToken* T100FileScan::getToken()
{
    return m_token;
}

T100SegmentToken* T100FileScan::getItem()
{
    return &m_item;
}

T100BOOL T100FileScan::append()
{
    m_token->segments.push_back(m_item.copy());

    return T100TRUE;
}

T100BOOL T100FileScan::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scan->next(m_item);
    if(result){
        setLoaded(T100TRUE);
    }else{

    }

    return result;
}

T100BOOL T100FileScan::next(IToken& token)
{
    m_token = (T100FileToken*)&token;
    m_token->clear();

    m_token->type   = T100FILE_SOURCE;

    return run();
}

T100BOOL T100FileScan::run()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result)return T100FALSE;
    }

    switch(m_item.type)
    {
    case T100TOKEN_EOF:
        {
            m_token->type       = T100TOKEN_EOF;
            m_token->eof        = m_item.eof;
            m_token->row        = m_item.row;
            return T100TRUE;
            break;
        }
    case T100SEGMENT_IMPORT:
        {
            m_token->type       = T100FILE_IMPORT;
            m_token->file       = getFile();
            setLoaded(T100FALSE);

            T100AssemblyLog::info(T100LOG_FILE, T100AssemblyHint::file_hint(m_token->file.to_std_string(), T100FILESCAN_IMPORT_FILE));

            return T100TRUE;
            break;
        }
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
                    T100AssemblyLog::info(T100LOG_FILE, T100AssemblyHint::file_hint(m_token, ""));
                    return T100TRUE;
                    break;
                }
            default:
                append();
                setLoaded(T100FALSE);
            };
        }while(T100TRUE);
    };

    return result;
}

T100String T100FileScan::getFile()
{
    T100String result;

    if(1 == m_item.sentences.size()){
        T100SentenceToken *token = m_item.sentences[0];

        if(T100SENTENCE_IMPORT == token->type){
            T100SentenceImport *data = (T100SentenceImport*)(token->data);

            result = data->file;
        }
    }

    return result;
}
