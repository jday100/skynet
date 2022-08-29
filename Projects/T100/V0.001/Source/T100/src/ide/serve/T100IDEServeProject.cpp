#include "T100IDEServeProject.h"

#include "T100IDEServe.h"


T100IDEServeProject::T100IDEServeProject(T100IDEServe* serve)
    :T100IDEServeBase(serve)
{
    //ctor
}

T100IDEServeProject::~T100IDEServeProject()
{
    //dtor
}

T100BOOL T100IDEServeProject::exist()
{
    return T100FALSE;
}

T100BOOL T100IDEServeProject::create()
{
    return T100FALSE;
}

T100BOOL T100IDEServeProject::open()
{
    return T100FALSE;
}

T100BOOL T100IDEServeProject::close()
{
    return T100FALSE;
}

T100BOOL T100IDEServeProject::opened()
{
    return T100FALSE;
}
