#include "T100SentenceLabel.h"

#include "T100FileData.h"
#include "T100SentenceScan.h"


T100SentenceLabel::T100SentenceLabel(T100SentenceScan* scan)
    :T100Sentence(scan)
{
    //ctor
}

T100SentenceLabel::~T100SentenceLabel()
{
    //dtor
}

T100BOOL T100SentenceLabel::parse()
{
    T100BOOL    result      = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        name            = m_item->data;
        type            = T100SENTENCE_LABEL;
        m_token->type   = T100SENTENCE_LABEL;
    }

    return result;
}

T100BOOL T100SentenceLabel::build(T100FileData* code)
{
    code->setLabel(name, code->getOffset());

    T100LABEL_DEFINE*   ld = T100NEW T100LABEL_DEFINE;

    ld->isvirtual       = code->getCode()->isVirtual;
    ld->isshare         = code->getCode()->isShare;
    ld->name            = name;
    ld->offset          = code->getOffset();

    T100Code::setLabelDefine(name, ld);

    return T100TRUE;
}
