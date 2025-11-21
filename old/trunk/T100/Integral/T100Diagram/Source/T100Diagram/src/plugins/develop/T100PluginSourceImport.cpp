#include "T100PluginSourceImport.h"

#include "T100Folder.h"
#include "T100SourceImportInfo.h"

T100PluginSourceImport::T100PluginSourceImport()
{
    //ctor
}

T100PluginSourceImport::~T100PluginSourceImport()
{
    //dtor
}

T100SOURCE_IMPORT_FILE_INFO_VECTOR& T100PluginSourceImport::GetFiles()
{
    return m_files;
}

T100BOOL T100PluginSourceImport::Run(T100SourceImportInfo* info)
{
    if(!info){
        return T100FALSE;
    }
    ScanFolder(info, info->Source);
}

T100BOOL T100PluginSourceImport::ScanFolder(T100SourceImportInfo* info, T100WSTRING& path)
{
    T100Folder              folder(path);
    T100WSTRING_VECTOR      folders;
    T100WSTRING_VECTOR      files;

    //folder.List(files, L"*.h;*.hpp;*.c;*.cpp;*.inl");
    folder.List(folders, files);

    for(T100WSTRING& file : files){
        Append(file);
    }

    for(T100WSTRING& name : folders){
        T100WSTRING     current = path + L"\\" + name;
        ScanFolder(info, current);
    }
}

T100BOOL T100PluginSourceImport::Append(T100WSTRING& file)
{
    if(m_search.find(file) == m_search.end()){
        T100SourceImportFileInfo*       info    = T100NEW T100SourceImportFileInfo();

        info->FileName      = file;
        m_search[file]      = info;
        m_files.push_back(info);
    }
}
