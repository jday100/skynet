#include "T100ClassPathDrawer.h"

#include "T100File.h"


T100ClassPathDrawer::T100ClassPathDrawer()
{
    //ctor
}

T100ClassPathDrawer::~T100ClassPathDrawer()
{
    //dtor
}

T100VOID T100ClassPathDrawer::setRoot(T100String root)
{
    m_root = root;
}

T100String T100ClassPathDrawer::getRoot()
{
    return m_root;
}

T100BOOL T100ClassPathDrawer::append(T100String& path)
{
    m_paths.push_back(path);
    return T100TRUE;
}

T100BOOL T100ClassPathDrawer::find(T100String file, T100String& result)
{
    for(T100String& item : m_paths){
        T100String      path;

        path = m_root + L"\\" + file;

        T100File    target(path.to_wstring());

        if(target.exists()){
            result = path;
            return T100TRUE;
        }
    }

    for(T100String& item : m_paths){
        T100String      path;

        path = item + L"\\" + file;

        T100File    target(path.to_wstring());

        if(target.exists()){
            result = path;
            return T100TRUE;
        }
    }

    for(T100String& item : m_paths){
        T100String      path;

        path = m_root + L"\\" + item + L"\\" + file;

        T100File    target(path.to_wstring());

        if(target.exists()){
            result = path;
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100ClassPathDrawer::clear()
{
    m_paths.clear();
    return T100TRUE;
}
