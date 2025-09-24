#include "T100FolderServe.h"

#include <io.h>
#include "T100Folder.h"
#include "T100ProjectConfig.h"

T100FolderServe::T100FolderServe()
{
    //ctor
}

T100FolderServe::~T100FolderServe()
{
    //dtor
}

T100BOOL T100FolderServe::IsExists(const T100WSTRING& path)
{
    T100INT     result;

    result = ::_waccess(path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FolderServe::List(T100FolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100Folder      folder(info->GetPath());

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();

    T100WSTRING_VECTOR          fileNames;
    T100WSTRING_VECTOR          folderNames;

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){

        T100WSTRING     thisPath    = info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;

        T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

        thisInfo->SetLabel(item);
        thisInfo->SetPath(thisPath);

        folders.push_back(thisInfo);
    }

    for(const T100WSTRING& item : fileNames){
        T100WSTRING         thisPath        = info->GetPath() + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
        T100FileInfo*       thisFile        = T100NEW T100FileInfo();

        thisFile->SetLabel(item);
        thisFile->SetFileName(item);
        thisFile->SetPath(thisPath);

        files.push_back(thisFile);
    }

    return T100TRUE;
}

T100BOOL T100FolderServe::Clear()
{
    return T100TRUE;
}
