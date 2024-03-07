#include "T100ProjectServe.h"

namespace T100PROJECT{

T100ProjectServe::T100ProjectServe()
{
    //ctor
}

T100ProjectServe::~T100ProjectServe()
{
    //dtor
}

T100VOID T100ProjectServe::create()
{
    m_project_drawer    = T100NEW T100ProjectDrawer();
}

T100VOID T100ProjectServe::destroy()
{
    T100SAFE_DELETE(m_project_drawer)
}

T100BOOL T100ProjectServe::SaveFile(T100STRING file)
{

}

T100BOOL T100ProjectServe::LoadFile(T100STRING file)
{

}

T100VOID T100ProjectServe::setModified(T100BOOL flag)
{

}

T100BOOL T100ProjectServe::IsModified()
{

}

T100VOID T100ProjectServe::DiscardEdits()
{

}

T100BOOL T100ProjectServe::opened()
{

}

T100BOOL T100ProjectServe::NewFile(T100STRING& file, T100MansionInfo*& mansion)
{

}

T100BOOL T100ProjectServe::OpenFile(T100STRING& file, T100MansionInfo* mansion)
{

}

T100BOOL T100ProjectServe::CloseFile()
{

}

T100BOOL T100ProjectServe::Save()
{

}

T100BOOL T100ProjectServe::SaveAs()
{

}

T100BOOL T100ProjectServe::Quit()
{

}

T100MansionInfo* T100ProjectServe::getCurrent()
{

}

T100ProjectDrawer* T100ProjectServe::getProjectDrawer()
{

}

}
