#include "T100FolderLogic.h"

#include <io.h>
#include "T100Folder.h"
#include "T100WxFolderInfo.h"

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

T100BOOL T100FolderLogic::Open(const T100WSTRING& path, T100FolderInfo* info)
{
    T100Folder      folder(path);

    if(!folder.IsExists()){
        return T100FALSE;
    }

    T100FILE_INFO_VECTOR&       files       = info->GetFiles();
    T100FOLDER_INFO_VECTOR&     folders     = info->GetSubFolders();
    //T100PROJECT_INFO_VECTOR&    projects    = info->GetProjects();

    T100WSTRING_VECTOR          fileNames;
    T100WSTRING_VECTOR          folderNames;

    folder.List(folderNames, fileNames);

    for(const T100WSTRING& item : folderNames){
        T100WxFolderInfo        thisFolder;

        thisFolder.SetLabel(item);
        T100WSTRING     thisPath    = path + L"/" + item;
        thisFolder.SetPath(thisPath);

        T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

        thisInfo->SetLabel(item);
        thisInfo->SetPath(thisPath);

        folders.push_back(thisInfo);


        /*
        if(m_projectServe.Check(&thisFolder)){
            T100ProjectInfo*    thisProject     = T100NEW T100ProjectInfo();

            projects.push_back(thisProject);
        }else{
            T100FolderInfo*     thisInfo        = T100NEW T100FolderInfo();

            thisInfo->SetLabel(item);

            folders.push_back(thisInfo);
        }
        */
    }

    for(const T100WSTRING& item : fileNames){
        T100WSTRING         thisPath        = path + L"/" + item;
        T100FileInfo*       thisFile        = T100NEW T100FileInfo();

        thisFile->SetFileName(item);
        thisFile->SetPath(thisPath);

        files.push_back(thisFile);
    }

    return T100TRUE;
}
