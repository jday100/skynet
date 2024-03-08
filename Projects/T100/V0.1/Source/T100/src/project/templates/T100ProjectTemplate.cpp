#include "T100ProjectTemplate.h"

namespace T100PROJECT{

T100ProjectTemplate::T100ProjectTemplate(T100MansionDrawer* drawer, T100ProjectInfo* info)
    :m_drawer(drawer), m_info(info)
{
    //ctor
}

T100ProjectTemplate::~T100ProjectTemplate()
{
    //dtor
}

T100ProjectInfo* T100ProjectTemplate::getProjectInfo()
{
    return m_info;
}

T100MansionDrawer* T100ProjectTemplate::getMansionDrawer()
{
    return m_drawer;
}

}
