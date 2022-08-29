#include "T100Folder.h"


T100Folder::T100Folder(T100String folder)
    :m_folder(folder)
{
    //ctor
}

T100Folder::~T100Folder()
{
    //dtor
}

T100BOOL T100Folder::exists()
{
    T100INTEGER result;

    result = ::_access(m_folder.to_std_string().c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Folder::getAllFolders(T100STDSTRING_VECTOR& folders)
{
    ::_finddata_t   info;
    long            handle;

    handle  = ::_findfirst("*", &info);
    if(-1L == handle){
        return T100FALSE;
    }

    do{
        if(-1L == handle){
            //::_findclose(handle);
            return T100FALSE;
        }

        if(info.attrib & _A_SUBDIR){
            if(0 != strcmp(info.name, ".") && 0 != strcmp(info.name, "..")){
                folders.push_back(info.name);
            }
        }

    }while(0 == ::_findnext(handle, &info));

    ::_findclose(handle);

    return T100TRUE;
}

T100BOOL T100Folder::getAllFolders(T100FILE_VECTOR& files)
{
    ::_finddata_t   info;
    T100LONG        handle      = 0;
    T100STDSTRING   name;

    name    = m_folder.to_std_string() + "\\*.*";

    handle  = ::_findfirst(name.c_str(), &info);
    if(-1 == handle)return T100FALSE;
    parse(info, files);

    while(!::_findnext(handle, &info)){
        parse(info, files);
    }
    ::_findclose(handle);

    return T100TRUE;
}

T100VOID T100Folder::parse(::_finddata_t& info, T100FILE_VECTOR& files)
{
    if(strcmp(info.name, ".") && strcmp(info.name, "..")){
        T100FileInfo* file = new T100FileInfo();

        file->path   = m_folder.to_std_string();
        file->name   = info.name;
        file->size   = info.size;

        if(info.attrib & T100FILE_READONLY){
            file->READONLY  = T100TRUE;
        }

        if(info.attrib & T100FILE_HIDDEN){
            file->HIDDEN    = T100TRUE;
        }

        if(info.attrib & T100FILE_SYSTEM){
            file->SYSTEM    = T100TRUE;
        }

        if(info.attrib & T100FILE_SUBDIR){
            file->SUBDIR    = T100TRUE;
        }

        if(info.attrib & T100FILE_ARCH){
            file->ARCH      = T100TRUE;
        }

        files.push_back(file);
    }
}
