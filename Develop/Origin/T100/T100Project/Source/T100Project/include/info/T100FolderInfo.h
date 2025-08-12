#ifndef T100FOLDERINFO_H
#define T100FOLDERINFO_H

#include "T100FileInfo.h"

#define     T100FOLDER_INFO_VECTOR                  std::vector<T100FolderInfo*>

class T100FolderInfo
{
    public:
        T100FolderInfo();
        virtual ~T100FolderInfo();

        T100VOID                    SetLabel(const T100WSTRING&);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

        T100FILE_INFO_VECTOR&       GetFiles();
        T100FOLDER_INFO_VECTOR&     GetSubFolders();

    protected:
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;

        T100FILE_INFO_VECTOR        m_files;
        T100FOLDER_INFO_VECTOR      m_folders;

    private:
};

#endif // T100FOLDERINFO_H
