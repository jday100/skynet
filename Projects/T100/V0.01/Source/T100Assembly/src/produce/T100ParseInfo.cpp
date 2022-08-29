#include "T100ParseInfo.h"

#include "T100VariableDrawer.h"
#include "T100LabelDrawer.h"
#include "T100ProcedureDrawer.h"

T100VariableDrawer      T100ParseInfo::m_variable_drawer;
T100LabelDrawer         T100ParseInfo::m_label_drawer;
T100ProcedureDrawer     T100ParseInfo::m_procedure_drawer;


T100ParseInfo::T100ParseInfo()
{
    //ctor
}

T100ParseInfo::~T100ParseInfo()
{
    //dtor
}

T100VOID T100ParseInfo::setToken(T100PartToken* token)
{
    m_token = token;
}

T100PartToken* T100ParseInfo::getToken()
{
    return m_token;
}












T100VariableDrawer& T100ParseInfo::getVariableDrawer()
{
    return m_variable_drawer;
}

T100LabelDrawer& T100ParseInfo::getLabelDrawer()
{
    return m_label_drawer;
}

T100ProcedureDrawer& T100ParseInfo::getProcedureDrawer()
{
    return m_procedure_drawer;
}
