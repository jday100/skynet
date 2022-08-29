#include "T100IDEStore.h"

T100IDEStore::T100IDEStore()
{
    //ctor
    create();
}

T100IDEStore::~T100IDEStore()
{
    //dtor
    destroy();
}

T100VOID T100IDEStore::create()
{
    m_project       = T100NEW T100IDEStoreProject(this);
    m_editor        = T100NEW T100IDEStoreEditor(this);
}

T100VOID T100IDEStore::destroy()
{

}

T100IDEStoreProject* T100IDEStore::getProject()
{
    return m_project;
}

T100IDEStoreEditor* T100IDEStore::getEditor()
{
    return m_editor;
}
