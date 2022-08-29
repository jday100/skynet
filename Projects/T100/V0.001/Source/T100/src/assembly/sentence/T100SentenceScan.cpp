#include "T100SentenceScan.h"

#include "T100AllSentences.h"


T100SentenceScan::T100SentenceScan()
{
    //ctor
}

T100SentenceScan::~T100SentenceScan()
{
    //dtor
}

T100BOOL T100SentenceScan::open(T100String& file)
{
    m_scan = T100NEW T100KeywordScan();
    return m_scan->open(file);
}

T100BOOL T100SentenceScan::close()
{
    T100BOOL result;

    result = m_scan->close();

    if(result){
        T100DELETE(m_scan);
        m_scan = T100NULL;
    }

    return result;
}

T100SentenceToken* T100SentenceScan::getToken()
{
    return m_token;
}

T100KeywordToken* T100SentenceScan::getItem()
{
    return &m_item;
}

T100BOOL T100SentenceScan::append()
{
    m_token->data   = m_sentence;
    m_token->eof    = m_item.eof;
    m_token->err    = m_item.err;
    m_token->row    = m_item.row;

    return T100TRUE;
}

T100BOOL T100SentenceScan::read()
{
    T100BOOL    result      = T100FALSE;

    result = m_scan->next(m_item);
    if(!result){
        return T100FALSE;
    }else{
        setLoaded(T100TRUE);
    }

    return T100TRUE;
}

T100BOOL T100SentenceScan::next(IToken& token)
{
    m_token = (T100SentenceToken*)&token;
    m_token->clear();

    //T100Assembly::m_console.get();

    return run();
}

T100BOOL T100SentenceScan::run()
{
    T100BOOL    result      = T100FALSE;

READ_NEXT:

    result = read();
    if(!result){
        return T100FALSE;
    }

    switch(m_item.type){
    case T100KEYWORD_VARIABLE:
        {
            m_sentence = T100NEW T100SentenceVariable(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_LABEL:
        {
            m_sentence = T100NEW T100SentenceLabel(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_PROCEDURE:
        {
            m_sentence = T100NEW T100SentenceProcedure(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_MODE:
        {
            m_sentence = T100NEW T100SentenceMode(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_IMPORT:
        {
            m_sentence = T100NEW T100SentenceImport(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_CODE:
        {
            m_sentence = T100NEW T100SentenceCode(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_DATA:
        {
            m_sentence = T100NEW T100SentenceData(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_END:
        {
            m_sentence = T100NEW T100SentenceEnd(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_COMMENT:
        {
            m_sentence = T100NEW T100SentenceComment(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type       = T100TOKEN_EOF;
            m_token->eof        = T100TRUE;
            m_token->row        = m_item.row;
            result              = T100TRUE;

            break;
        }
    case T100TOKEN_BR:
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;

            break;
        }
    default:
        result = parseOrder();
    };

    if(result){
        append();

        T100AssemblyLog::info(T100LOG_SENTENCE, T100AssemblyHint::sentence_hint(getToken(), T100SENTENCESCAN_SENTENCE_READ_SUCCESS));
    }else{
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(getToken(), T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));

        nextLine();
        setLoaded(T100FALSE);
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100SentenceScan::parseOrder()
{
    T100BOOL    result      = T100FALSE;

    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item.type)
    {
    case T100KEYWORD_ADD:
        {
            m_sentence = T100NEW T100SentenceAdd(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_SUB:
        {
            m_sentence = T100NEW T100SentenceSub(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_MUL:
        {
            m_sentence = T100NEW T100SentenceMul(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_DIV:
        {
            m_sentence = T100NEW T100SentenceDiv(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
        //
    case T100KEYWORD_AND:
        {
            m_sentence = T100NEW T100SentenceAnd(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_OR:
        {
            m_sentence = T100NEW T100SentenceOr(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_NOT:
        {
            m_sentence = T100NEW T100SentenceNot(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_XOR:
        {
            m_sentence = T100NEW T100SentenceXor(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
        //
    case T100KEYWORD_LOCK:
        {
            m_sentence = T100NEW T100SentenceLock(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_UNLOCK:
        {
            m_sentence = T100NEW T100SentenceUnlock(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_NOP:
        {
            m_sentence = T100NEW T100SentenceNop(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_HALT:
        {
            m_sentence = T100NEW T100SentenceHalt(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_CMT:
        {
            m_sentence = T100NEW T100SentenceCmt(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_DEBUG:
        {
            m_sentence = T100NEW T100SentenceDebug(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
        //
    case T100KEYWORD_CALL:
        {
            m_sentence = T100NEW T100SentenceCall(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_RETURN:
        {
            m_sentence = T100NEW T100SentenceRet(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_INT:
        {
            m_sentence = T100NEW T100SentenceInt(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_IRET:
        {
            m_sentence = T100NEW T100SentenceIret(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_JUMP:
        {
            m_sentence = T100NEW T100SentenceJump(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_JZ:
        {
            m_sentence = T100NEW T100SentenceJz(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_JNZ:
        {
            m_sentence = T100NEW T100SentenceJnz(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
        //
    case T100KEYWORD_LOOP:
        {
            m_sentence = T100NEW T100SentenceLoop(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_IN:
        {
            m_sentence = T100NEW T100SentenceIn(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_OUT:
        {
            m_sentence = T100NEW T100SentenceOut(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    case T100KEYWORD_MOVE:
        {
            m_sentence = T100NEW T100SentenceMove(this);

            m_sentence->data = m_item.data;
            result = m_sentence->parse();
            if(result){
                result = parseTail();
            }

            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        result          = T100FALSE;
    };

    return result;
}

T100BOOL T100SentenceScan::parseTail()
{
    T100BOOL    result      = T100FALSE;

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
                setLoaded(T100FALSE);
                return T100TRUE;

                break;
            }
        case T100TOKEN_BR:
            {
                setLoaded(T100FALSE);
                return T100TRUE;

                break;
            }
        case T100KEYWORD_COMMENT:
            {
                setLoaded(T100FALSE);

                break;
            }
        default:
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            return T100FALSE;

            break;
        };
    }while(T100TRUE);

    return T100FALSE;
}

T100VOID T100SentenceScan::nextLine()
{
    if(isLoaded()){
        if(T100TOKEN_BR == m_item.type){
            setLoaded(T100FALSE);
        }
    }else{
        while(read()){
            if(m_item.eof)break;
            if(T100TOKEN_BR == m_item.type){
                setLoaded(T100FALSE);
                break;
            }
        }
    }
}
