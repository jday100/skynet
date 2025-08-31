#include "T100FolderLogic.h"

#include <io.h>
#include "T100Folder.h"
#include "T100WxFolderInfo.h"
#include "T100ProjectConfig.h"

T100FolderLogic::T100FolderLogic()
{
    //ctor
}

T100FolderLogic::~T100FolderLogic()
{
    //dtor
}

T100BOOL T100FolderLogic::IsExists(const T100WSTRING& path)
{
    T100INT     result;

    result = ::_waccess(path.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FolderLogic::Create(const T100WSTRING&)
{

}

T100BOOL T100FolderLogic::Remove(T100FolderInfo*)
{

}

T100BOOL T100FolderLogic::List(const T100WSTRING& path, T100FolderInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100Folder      folder(path);

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();

    T100WSTRING_VECTOR          fileNames;
    T100WSTRING_VECTOR          folderNames;

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
        T100WxFolderInfo        thisFolder;

        thisFolder.SetLabel(item);
        T100WSTRING     thisPath    = path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
        thisFolder.SetPath(thisPath);

        T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

        thisInfo->SetLabel(item);
        thisInfo->SetPath(thisPath);

        folders.push_back(thisInfo);
    }

    for(const T100WSTRING& item : fileNames){
        T100WSTRING         thisPath        = path + T100ProjectConfig::T100PROJECT_STORAGE_SEPARATOR + item;
        T100FileInfo*       thisFile        = T100NEW T100FileInfo();

        thisFile->SetLabel(item);
        thisFile->SetFileName(item);
        thisFile->SetPath(thisPath);

        files.push_back(thisFile);
    }

    return T100TRUE;
}

T100BOOL T100FolderLogic::Rename(T100FolderInfo*)
{

}
