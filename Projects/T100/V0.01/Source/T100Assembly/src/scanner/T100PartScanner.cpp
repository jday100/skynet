#include "T100PartScanner.h"

T100PartScanner::T100PartScanner()
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

}

T100VOID T100PartScanner::destroy()
{

}

T100VOID T100PartScanner::setSource(T100Scanner* scanner)
{
    m_scanner = dynamic_cast<T100SegmentScanner*>(scanner);
}

T100Scanner* T100PartScanner::getSource()
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
    }else{

    }

    return result;
}

T100BOOL T100PartScanner::next(T100Token& token)
{
    m_token = (T100PartToken*)&token;
    m_token->clear();

    m_token->type   = T100FILE_SOURCE;

    return run();
}

T100BOOL T100PartScanner::run()
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
            //m_token->file       = getFile();
            setLoaded(T100FALSE);

            //T100AssemblyLog::info(T100LOG_FILE, T100AssemblyHint::file_hint(m_token->file.to_std_string(), T100FILESCAN_IMPORT_FILE));

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
                    //T100AssemblyLog::info(T100LOG_FILE, T100AssemblyHint::file_hint(m_token, ""));
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
