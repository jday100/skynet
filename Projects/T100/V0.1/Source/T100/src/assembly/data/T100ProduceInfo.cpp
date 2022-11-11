#include "T100ProduceInfo.h"

#include "T100PartDrawer.h"
#include "T100VariableDrawer.h"
#include "T100LabelDrawer.h"
#include "T100ProcedureDrawer.h"

namespace T100Assembly{

T100STRING              T100ProduceInfo::m_name;
T100MODE                T100ProduceInfo::m_mode                 = T100MODE_NONE;

T100BOOL                T100ProduceInfo::m_code_default         = T100FALSE;
T100BOOL                T100ProduceInfo::m_data_default         = T100FALSE;
T100SegmentCode*        T100ProduceInfo::m_code                 = T100NULL;
T100SegmentData*        T100ProduceInfo::m_data                 = T100NULL;
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

T100VOID T100ProduceInfo::setName(T100STRING& name)
{
    m_name = name;
}

T100STRING& T100ProduceInfo::getName()
{
    return m_name;
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

T100BOOL T100ProduceInfo::clear()
{
    m_mode          = T100MODE_NONE;
    m_code_default  = T100FALSE;
    m_data_default  = T100FALSE;

    m_code          = T100NULL;
    m_data          = T100NULL;

    m_part_drawer.clear();
    m_variable_drawer.clear();
    m_label_drawer.clear();
    m_procedure_drawer.clear();

    return T100TRUE;
}

T100BOOL T100ProduceInfo::setDefaultCode(T100SegmentCode* code)
{
    if(m_code){
        return T100FALSE;
    }

    m_code = code;
    return T100TRUE;
}

T100BOOL T100ProduceInfo::setDefaultData(T100SegmentData* data)
{
    if(m_data){
        return T100FALSE;
    }

    m_data = data;
    return T100TRUE;
}

}
