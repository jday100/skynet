#include "T100SentenceImport.h"

#include "T100String32Tools.h"

namespace T100Assembly{

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
        result = T100Library::T100String32Tools::format(m_item->value, file);
        if(!result){
            return T100FALSE;
        }
        setLoaded(T100FALSE);

        //result = createPartInfo(file);
    }else{
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100SentenceImport::build(T100BuildInfo* info)
{
    return T100TRUE;
}

}
