#include "T100IDEProjectPlaten.h"

#include <wx/aui/aui.h>
#include "T100IDEView.h"
#include "T100IDEViewManager.h"

namespace T100IDE{

T100IDEProjectPlaten::T100IDEProjectPlaten(T100IDEView* view)
    :T100IDEPlatenBase(view)
{
    //ctor
}

T100IDEProjectPlaten::~T100IDEProjectPlaten()
{
    //dtor
}

T100BOOL T100IDEProjectPlaten::create()
{
    return T100TRUE;
}

T100VOID T100IDEProjectPlaten::destroy()
{

}

::T100ProjectProjectsPanel* T100IDEProjectPlaten::getProjectsPanel()
{
    return m_projects_panel;
}

T100BOOL T100IDEProjectPlaten::show()
{
    return T100TRUE;
}

T100BOOL T100IDEProjectPlaten::hide()
{
    return T100TRUE;
}

T100VOID T100IDEProjectPlaten::setProject(T100PROJECT::T100Project* project)
{

}

}
