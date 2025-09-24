#ifndef T100FOLDERINFO_H
#define T100FOLDERINFO_H

#include <atomic>
#include "T100FileInfo.h"

#define     T100FOLDER_INFO_VECTOR                      std::vector<T100FolderInfo*>

class T100FolderInfo
{
    public:
        T100FolderInfo();
        virtual ~T100FolderInfo();

        T100VOID                    SetOpened(T100BOOL);
        T100BOOL                    IsOpened();

        T100VOID                    SetLabel(const T100WSTRING&);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

        T100VOID                    SetFolder(const T100WSTRING&);
        const T100WSTRING&          GetFolder();

        T100FILE_INFO_VECTOR&       GetFiles();
        T100FOLDER_INFO_VECTOR&     GetSubFolders();

    protected:
        std::atomic_bool            m_opened;
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;
        T100WSTRING                 m_folder;

        T100FILE_INFO_VECTOR        m_files;
        T100FOLDER_INFO_VECTOR      m_folders;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100FOLDERINFO_H
