#include "T100SentenceLabel.h"

#include "T100ProduceInfo.h"
#include "T100LabelDrawer.h"


T100SentenceLabel::T100SentenceLabel(T100SentenceScanner* scanner)
    :T100Sentence(scanner)
{
    //ctor
}

T100SentenceLabel::~T100SentenceLabel()
{
    //dtor
}

T100BOOL T100SentenceLabel::parse()
{
    T100BOOL        result          = T100TRUE;

    setLoaded(T100FALSE);

    if(result){
        name            = m_item->value;
        type            = T100SENTENCE_LABEL;
        m_token->type   = T100SENTENCE_LABEL;

        result = setDefine(name);
    }

    return result;
}

T100BOOL T100SentenceLabel::build(T100BuildInfo* info)
{
    info->setLabel(name, info->getOffset());

    return T100TRUE;
}

T100BOOL T100SentenceLabel::setDefine(T100String& name)
{
    T100BOOL            result          = T100TRUE;

    T100LABEL_DEFINE*   ld = T100NEW T100LABEL_DEFINE();

    ld->name        = name;

    result = T100ProduceInfo::getLabelDrawer().setLabelDefine(name, ld);
    if(!result){
        T100SAFE_DELETE(ld);
    }

    return result;
}
