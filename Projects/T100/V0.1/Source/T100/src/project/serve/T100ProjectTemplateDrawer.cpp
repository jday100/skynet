#include "T100ProjectTemplateDrawer.h"

#include "T100ProjectTemplate.h"
#include "T100TemplateProjectEmpty.h"

namespace T100PROJECT{

T100ProjectTemplateDrawer::T100ProjectTemplateDrawer(T100MansionDrawer* drawer)
    :m_drawer(drawer)
{
    //ctor
}

T100ProjectTemplateDrawer::~T100ProjectTemplateDrawer()
{
    //dtor
}

T100BOOL T100ProjectTemplateDrawer::Create(T100ProjectInfo* info)
{
    T100BOOL                        result          = T100FALSE;
    T100ProjectTemplate*            project         = T100NULL;

    if(info){

    }else{
        return T100FALSE;
    }

    switch(info->getType()){
    case T100PROJECT_TYPE_EMPTY:
        {
            project = T100NEW T100TemplateProjectEmpty(m_drawer, info);
        }
        break;
    default:
        return T100FALSE;
    }

    if(project){
        result  = project->Create();
    }

    return result;
}

}
