#include "T100TemplateProjectEmpty.h"

#include "T100ProjectDrawer.h"
#include "T100MansionDrawer.h"

namespace T100PROJECT{

T100TemplateProjectEmpty::T100TemplateProjectEmpty(T100MansionDrawer* drawer, T100ProjectInfo* info)
    :T100ProjectTemplate(drawer, info)
{
    //ctor
}

T100TemplateProjectEmpty::~T100TemplateProjectEmpty()
{
    //dtor
}

T100BOOL T100TemplateProjectEmpty::Create()
{
    T100BOOL            result;

    //result  = getMansionDrawer()->getProjectDrawer()->Create(getProjectInfo());



    return T100FALSE;
}

}
