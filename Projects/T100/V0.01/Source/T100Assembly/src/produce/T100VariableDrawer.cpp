#include "T100VariableDrawer.h"

T100VARIABLE_HASH           T100VariableDrawer::m_variable_hash;


T100VariableDrawer::T100VariableDrawer()
{
    //ctor
}

T100VariableDrawer::~T100VariableDrawer()
{
    //dtor
}

T100BOOL T100VariableDrawer::setVariableDefine(T100String key, T100VARIABLE_DEFINE* var)
{
    m_variable_hash[key] = var;

    return T100TRUE;
}

T100VARIABLE_DEFINE* T100VariableDrawer::getVariableDefine(T100String key)
{
    T100VARIABLE_DEFINE*                result          = T100NULL;
    T100VARIABLE_HASH::iterator         it;

    it = m_variable_hash.find(key);

    if(it == m_variable_hash.end()){

    }else{
        result = it->second;
    }

    return result;
}
