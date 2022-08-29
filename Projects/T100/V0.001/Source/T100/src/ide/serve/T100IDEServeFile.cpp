#include "T100IDEServeFile.h"

#include "T100IDEServe.h"


T100IDEServeFile::T100IDEServeFile(T100IDEServe* serve)
    :T100IDEServeBase(serve)
{
    //ctor
}

T100IDEServeFile::~T100IDEServeFile()
{
    //dtor
}

T100BOOL T100IDEServeFile::exist()
{
    return T100FALSE;
}

T100BOOL T100IDEServeFile::create()
{
    return T100FALSE;
}

T100BOOL T100IDEServeFile::open(T100STDSTRING file, T100EditorData* data)
{
    T100BOOL        result      = T100FALSE;
    T100IDEStore*   store;

    store = dynamic_cast<T100IDEStore*>(m_serve->getStore());

    if(!store){
        return T100FALSE;
    }

    result = store->getEditor()->open(file, data);

    if(result){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100IDEServeFile::close()
{
    return T100FALSE;
}

T100BOOL T100IDEServeFile::opened()
{
    return T100FALSE;
}

T100BOOL T100IDEServeFile::save(T100STDSTRING file, T100EditorData* data)
{
    return T100FALSE;
}
