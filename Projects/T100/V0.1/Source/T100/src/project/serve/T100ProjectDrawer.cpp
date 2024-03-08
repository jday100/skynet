#include "T100ProjectDrawer.h"

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

T100BOOL T100ProjectDrawer::Create(T100ProjectInfo* info)
{
    T100BOOL            result;

    result  = m_template_drawer->Create(info);

    return T100FALSE;
}

}
