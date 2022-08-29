#include "T100IDEStoreProject.h"

#include "T100Folder.h"


T100IDEStoreProject::T100IDEStoreProject(T100IDEStore* store)
    :T100IDEStoreBase(store)
{
    //ctor
}

T100IDEStoreProject::~T100IDEStoreProject()
{
    //dtor
}

T100BOOL T100IDEStoreProject::list(T100IDE_PROJECT_VECTOR& projects)
{
    T100Folder  folder(m_base);

    if(!folder.exists()){
        return T100FALSE;
    }

    T100FILE_VECTOR     result;

    if(folder.getAllFolders(result)){
        for(auto item : result){
            T100IDEProjectData*     data        = T100NULL;
            data = T100NEW T100IDEProjectData();
            if(data){
                data->m_folder  = item->name;

                projects.push_back(data);
            }else{
                return T100FALSE;
            }
        }
        return T100TRUE;
    }

    return T100FALSE;
}
