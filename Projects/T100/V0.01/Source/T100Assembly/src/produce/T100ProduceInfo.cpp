#include "T100ProduceInfo.h"

#include "T100PartDrawer.h"
#include "T100VariableDrawer.h"
#include "T100LabelDrawer.h"
#include "T100ProcedureDrawer.h"


T100MODE                T100ProduceInfo::m_mode                         = T100MODE_NONE;

T100BOOL                T100ProduceInfo::m_code_default                 = T100FALSE;
T100BOOL                T100ProduceInfo::m_data_default                 = T100FALSE;
T100PartDrawer          T100ProduceInfo::m_part_drawer;

T100VariableDrawer      T100ProduceInfo::m_variable_drawer;
T100LabelDrawer         T100ProduceInfo::m_label_drawer;
T100ProcedureDrawer     T100ProduceInfo::m_procedure_drawer;


T100ProduceInfo::T100ProduceInfo()
{
    //ctor
}

T100ProduceInfo::~T100ProduceInfo()
{
    //dtor
}

T100BOOL T100ProduceInfo::setMode(T100MODE mode)
{
    if(T100MODE_NONE == m_mode){
        m_mode = mode;
    }else if(mode != m_mode){
        return T100FALSE;
    }
    return T100TRUE;
}

T100MODE T100ProduceInfo::getMode()
{
    return m_mode;
}

T100PartDrawer& T100ProduceInfo::getPartDrawer()
{
    return m_part_drawer;
}

T100VariableDrawer& T100ProduceInfo::getVariableDrawer()
{
    return m_variable_drawer;
}

T100LabelDrawer& T100ProduceInfo::getLabelDrawer()
{
    return m_label_drawer;
}

T100ProcedureDrawer& T100ProduceInfo::getProcedureDrawer()
{
    return m_procedure_drawer;
}
