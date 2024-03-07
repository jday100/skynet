#include "T100MansionDrawer.h"

#include "T100PathTools.h"

namespace T100PROJECT{

T100MansionDrawer::T100MansionDrawer()
{
    //ctor
}

T100MansionDrawer::~T100MansionDrawer()
{
    //dtor
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
