#include "T100ClassPathDrawer.h"

#include "T100File.h"

namespace T100Assembly{

T100ClassPathDrawer::T100ClassPathDrawer()
{
    //ctor
}

T100ClassPathDrawer::~T100ClassPathDrawer()
{
    //dtor
}

T100VOID T100ClassPathDrawer::setRoot(T100STRING root)
{
    m_root = root;
}

T100STRING T100ClassPathDrawer::getRoot()
{
    return m_root;
}

T100BOOL T100ClassPathDrawer::append(T100STRING& path)
{
    m_paths.push_back(path);
    return T100TRUE;
}

T100BOOL T100ClassPathDrawer::find(T100STRING file, T100STRING& result)
{
    for(T100STRING& item : m_paths){
        T100STRING      path;

        path = m_root + L"\\" + file;

        T100File    target(path.to_wstring());

        if(target.exists()){
            result = path;
            return T100TRUE;
        }
    }

    fot(T100STRING& item : m_paths){
        T100STRING      path;

        path = item + L"\\" + file;

        T100File    target(path.to_wstring());

        if(target.exists()){
            result = path;
            return T100TRUE;
        }
    }

    for(T100STRING& item : m_paths){
        T100STRING      path;

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

}
