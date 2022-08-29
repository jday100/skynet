#include "T100IDECallbackFile.h"

#include "T100IDEStore.h"
#include "T100IDEServe.h"
#include "T100IDEView.h"

#include "T100EditorData.h"


T100IDECallbackFile::T100IDECallbackFile()
{
    //ctor
}

T100IDECallbackFile::~T100IDECallbackFile()
{
    //dtor
}

T100BOOL T100IDECallbackFile::frame_menu_new(void* d)
{
    m_view->getManager()->create_child(T100NULL);

    return T100FALSE;
}

T100BOOL T100IDECallbackFile::frame_menu_delete(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackFile::frame_menu_open(void* d)
{
    T100BOOL        result      = T100FALSE;
    T100STDSTRING   file;

    result = m_view->getFile()->open(file);

    if(!result){
        return T100FALSE;
    }

    T100EditorData*     data        = T100NULL;

    data = T100NEW T100EditorData();
    result = m_serve->getFile()->open(file, data);

    if(!result){
        return T100FALSE;
    }

    data->m_name = file;

    result = m_view->getManager()->create_child(data);

    return T100TRUE;
}

T100BOOL T100IDECallbackFile::frame_menu_close(void* d)
{
    return T100FALSE;
}

T100BOOL T100IDECallbackFile::frame_menu_save(void* d)
{
    T100BOOL            result;
    T100EditorData*     data        = T100NULL;

    data = m_view->getManager()->getCurrent()->getData();

    if(!data){
        return T100FALSE;
    }

    T100STDSTRING   file;
    //result = m_store->getEditor()->save(data);

    result = m_serve->getFile()->save(file, data);

    return T100FALSE;
}

T100BOOL T100IDECallbackFile::frame_menu_save_as(void* d)
{
    return T100FALSE;
}
