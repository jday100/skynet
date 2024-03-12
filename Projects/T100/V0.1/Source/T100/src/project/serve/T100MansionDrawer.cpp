#include "T100MansionDrawer.h"

#include "T100Folder.h"
#include "T100PathTools.h"

namespace T100PROJECT{

T100MansionDrawer::T100MansionDrawer()
{
    //ctor
    create();
}

T100MansionDrawer::~T100MansionDrawer()
{
    //dtor
    destroy();
}

T100VOID T100MansionDrawer::create()
{
    m_info              = T100NEW T100MansionInfo();
    m_project_drawer    = T100NEW T100ProjectDrawer(this);

    init();
}

T100VOID T100MansionDrawer::destroy()
{
    T100SAFE_DELETE(m_project_drawer);
    T100SAFE_DELETE(m_info);
}

T100STRING T100MansionDrawer::getName()
{
    return m_info->getName();
}

T100ProjectDrawer* T100MansionDrawer::getProjectDrawer()
{
    return m_project_drawer;
}

T100VOID T100MansionDrawer::init()
{
    T100Library::T100Folder             folder(m_info->getName().to_wstring());

    if(folder.exists()){
        m_project_drawer->Load();
    }else{
        if(T100Library::T100PathTools::mkdir(m_info->getName().to_wstring())){
            if(folder.exists()){

            }else{

            }
        }
    }
}

T100BOOL T100MansionDrawer::load(T100MansionInfo* mansion, T100PROJECT_INFO_VECTOR* projects)
{
    if(mansion){
        T100DIRECTORY_ENTRY_VECTOR      entries;
        T100Library::T100PathTools::enum_directories(mansion->getName().to_wstring(), entries);

        for(auto item : entries){
            if(item){
                T100ProjectInfo*        info        = T100NEW T100ProjectInfo();

                info->setName(item->getName());
                projects->push_back(info);
            }
        }
    }
}

}
