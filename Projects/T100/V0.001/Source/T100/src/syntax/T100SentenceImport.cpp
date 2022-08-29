#include "T100SentenceImport.h"

#include "T100AssemblyError.h"
#include "T100SentenceScan.h"


T100SentenceImport::T100SentenceImport(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceImport::~T100SentenceImport()
{
    //dtor
}

T100STDSTRING T100SentenceImport::tostring()
{
    T100STDSTRING result;

    result = "Import: ";
    result += "File: ";
    result += file.to_std_string();

    return result;
}

T100BOOL T100SentenceImport::parse()
{
    T100BOOL    result      = T100FALSE;

    result = read();
    if(!result){
        return T100FALSE;
    }

    if(T100CONSTANT_STRING == m_item->type){
        type            = T100SENTENCE_IMPORT;
        m_token->type   = T100SENTENCE_IMPORT;
        file            = m_item->data;
        setLoaded(T100FALSE);
    }else{
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCE_IMPORT_SYNTAX_ERROR));
        result = T100FALSE;
    }

    return result;
}
