#include "T100FileLogic.h"

#include <io.h>
#include "T100File.h"
#include "T100PathTools.h"

T100FileLogic::T100FileLogic() :
    m_openedFiles()
{
    //ctor
}

T100FileLogic::~T100FileLogic()
{
    //dtor
}

T100BOOL T100FileLogic::IsExists(const T100WSTRING& filename)
{
    T100INT     result;

    result = ::_waccess(filename.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100FileLogic::IsOpened(const T100WSTRING& path)
{
    T100FileInfo*   value   = T100NULL;

    value = m_openedFiles[path];

    if(value){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100FileLogic::Create(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100File        file(info->GetPath());

    //return file.Create();
}

T100BOOL T100FileLogic::Remove(T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100File        file(info->GetPath());

    //return file.Remove();
}

T100VOID T100FileLogic::Clear()
{
    m_openedFiles.clear();
}

T100BOOL T100FileLogic::Open(const T100WSTRING& path, T100FileInfo* info)
{
    if(!info){
        return T100FALSE;
    }

    T100File        file(path);

    if(!file.IsExists()){
        return T100FALSE;
    }

    T100FileInfo*   value   = T100NULL;

    value = m_openedFiles[path];

    if(value){
        return T100FALSE;
    }

    T100WSTRING         folder;
    T100WSTRING         filename;

    T100PathTools::Split(path, folder, filename);

    info->SetLabel(filename);
    info->SetFileName(filename);
    info->SetFolder(folder);
    info->SetOpened(T100TRUE);

    m_openedFiles[path] = info;

    return T100TRUE;
}

T100BOOL T100FileLogic::Close(const T100WSTRING& path)
{
    m_openedFiles.erase(path);

    return T100TRUE;
}

T100BOOL T100FileLogic::Rename(T100FileInfo*)
{

}
