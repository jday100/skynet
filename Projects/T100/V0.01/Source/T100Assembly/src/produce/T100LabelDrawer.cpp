#include "T100LabelDrawer.h"

T100LABEL_HASH          T100LabelDrawer::m_label_hash;


T100LabelDrawer::T100LabelDrawer()
{
    //ctor
}

T100LabelDrawer::~T100LabelDrawer()
{
    //dtor
}

T100BOOL T100LabelDrawer::setLabelDefine(T100String key, T100LABEL_DEFINE* label)
{
    m_label_hash[key] = label;

    return T100TRUE;
}

T100LABEL_DEFINE* T100LabelDrawer::getLabelDefine(T100String key)
{
    T100LABEL_DEFINE*               result          = T100NULL;
    T100LABEL_HASH::iterator        it;

    it = m_label_hash.find(key);

    if(it == m_label_hash.end()){

    }else{
        result = it->second;
    }

    return result;
}
