#include "T100SentenceLabel.h"

#include "T100ParseInfo.h"
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
    }

    return result;
}

T100BOOL T100SentenceLabel::build(T100BuildInfo* info)
{
    info->setLabel(name, info->getOffset());

    T100LABEL_DEFINE*   ld = T100NEW T100LABEL_DEFINE;

    /*
    ld->isvirtual       = info->getCode()->isVirtual;
    ld->isshare         = info->getCode()->isShare;
    ld->name            = name;
    ld->offset          = info->getOffset();
    */

    //T100ProduceInfo::setLabelDefine(name, ld);

    //T100ParseInfo::getLabelDrawer().setLabelDefine(name, ld);

    return T100TRUE;
}
