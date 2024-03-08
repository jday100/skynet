#include "T100ProjectDrawer.h"

#include "T100PathTools.h"
#include "T100MansionDrawer.h"

namespace T100PROJECT{

T100ProjectDrawer::T100ProjectDrawer(T100MansionDrawer* drawer)
    :m_mansion_drawer(drawer)
{
    //ctor
    create();
}

T100ProjectDrawer::~T100ProjectDrawer()
{
    //dtor
    destroy();
}

T100VOID T100ProjectDrawer::create()
{
    m_template_drawer   = T100NEW T100ProjectTemplateDrawer(m_mansion_drawer);
}

T100VOID T100ProjectDrawer::destroy()
{
    T100SAFE_DELETE(m_template_drawer);
}

T100BOOL T100ProjectDrawer::mkdir(T100ProjectInfo* info)
{
    T100BOOL        result;
    T100WSTRING     root;
    T100WSTRING     project;
    T100WSTRING     path;

    root    = m_mansion_drawer->getName().to_wstring();
    project = info->getName().to_wstring();

    result  = T100Library::T100PathTools::join(root, project, path);

    if(result){
        result  = T100Library::T100PathTools::mkdir(path);
    }
    return result;
}

T100BOOL T100ProjectDrawer::Create(T100ProjectInfo* info)
{
    T100BOOL            result;

    result  = m_template_drawer->Create(info);

    return T100FALSE;
}

}
