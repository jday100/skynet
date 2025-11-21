#include "T100PSVMStore.h"

#include "T100PSVMFile.h"

T100PSVMStore::T100PSVMStore()
{
    //ctor
}

T100PSVMStore::~T100PSVMStore()
{
    //dtor
}

T100WxFileInfo* T100PSVMStore::GetFile()
{
    return m_file;
}

T100BOOL T100PSVMStore::Load(T100WxFileInfo* file, T100PSVMInfo* info)
{
    if(file && info){

    }else{
        return T100FALSE;
    }

    m_file      = file;

    T100PSVMFile        psvm(file->m_path);

    if(psvm.Load(info)){
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100PSVMStore::Save(T100WxFileInfo* file, T100PSVMInfo* info)
{
    if(file && info){

    }else{
        return T100FALSE;
    }

    m_file  = file;
    if(!m_file){
        return T100FALSE;
    }

    T100PSVMFile        psvm(m_file->m_path);

    if(psvm.Save(info)){
        return T100TRUE;
    }
    return T100FALSE;
}
