#include "T100PainterServe.h"

#include "T100PainterCallback.h"
#include "T100ElementCircle.h"
#include "T100DiagramInfoV1.h"

namespace T100Painter{

T100PainterServe::T100PainterServe()
    :m_elements()
{
    //ctor
    create();
}

T100PainterServe::~T100PainterServe()
{
    //dtor
    destroy();
}

T100VOID T100PainterServe::create()
{
    m_opened    = T100FALSE;
    m_modified  = T100FALSE;
}

T100VOID T100PainterServe::destroy()
{

}

T100BOOL T100PainterServe::opened()
{
    return m_opened;
}

T100BOOL T100PainterServe::NewFile(T100STRING& file, T100DiagramInfo*& diagram)
{
    file        = L"unnamed.dgm";
    diagram     = T100NEW T100DiagramInfoV1();
    diagram->setFile(file);
    m_current   = diagram;
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100BOOL T100PainterServe::OpenFile(T100STRING& file, T100DiagramInfo* diagram)
{
    diagram->setFile(file);

    m_current   = diagram;
    m_opened    = T100TRUE;

    return T100TRUE;
}

T100BOOL T100PainterServe::CloseFile()
{
    m_opened    = T100FALSE;
    //m_current   = T100NULL;

    T100SAFE_DELETE(m_current);

    return T100TRUE;
}

T100BOOL T100PainterServe::Save()
{

}

T100BOOL T100PainterServe::SaveAs()
{

}

T100BOOL T100PainterServe::Quit()
{

}

T100DiagramInfo* T100PainterServe::getCurrent()
{
    return m_current;
}

T100BOOL T100PainterServe::SaveFile(T100STRING filename)
{
    T100PainterCallback::serve_file_save(&filename);
}

T100BOOL T100PainterServe::LoadFile(T100STRING filename)
{
    T100PainterCallback::serve_file_load(&filename);
}

T100VOID T100PainterServe::setModified(T100BOOL flag)
{
    m_modified = flag;
}

T100BOOL T100PainterServe::IsModified()
{
    return m_modified;
}

T100VOID T100PainterServe::DiscardEdits()
{

}

}
