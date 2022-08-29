#include "T100SentenceImport.h"

T100SentenceImport::T100SentenceImport(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceImport::~T100SentenceImport()
{
    //dtor
}

T100BOOL T100SentenceImport::parse()
{
    T100BOOL        result          = T100TRUE;

    result = read();
    if(!result){
        return T100FALSE;
    }

    if(T100CONSTANT_STRING == m_item->type){
        type            = T100SENTENCE_IMPORT;
        m_token->type   = T100SENTENCE_IMPORT;
        file            = m_item->value;
        setLoaded(T100FALSE);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100SentenceImport::build(T100BuildInfo* info)
{

}
