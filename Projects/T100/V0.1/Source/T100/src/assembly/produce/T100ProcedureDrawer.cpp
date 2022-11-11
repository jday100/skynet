#include "T100ProcedureDrawer.h"

namespace T100Assembly{

T100PROCEDURE_HASH          T100ProcedureDrawer::m_procedure_hash;

T100ProcedureDrawer::T100ProcedureDrawer()
{
    //ctor
}

T100ProcedureDrawer::~T100ProcedureDrawer()
{
    //dtor
}

T100BOOL T100ProcedureDrawer::setProcedureDefine(T100STRING key, T100PROCEDURE_DEFINE* proc)
{
    m_procedure_hash[key] = proc;
    return T100TRUE;
}

T100PROCEDURE_DEFINE* T100ProcedureDrawer::getProcedureDefine(T100STRING key)
{
    T100PROCEDURE_DEFINE*               result          = T100NULL;
    T100PROCEDURE_HASH::iterator        it;

    it = m_procedure_hash.find(key);

    if(it == m_procedure_hash.end()){

    }else{
        result = it->second;
    }
    return result;
}

T100BOOL T100ProcedureDrawer::clear()
{
    m_procedure_hash.clear();
    return T100TRUE;
}

}
