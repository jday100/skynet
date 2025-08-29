#ifndef T100PROJECTINFO_H
#define T100PROJECTINFO_H

#include <atomic>
#include "T100FileInfo.h"
#include "T100FolderInfo.h"

#define     T100PROJECT_INFO_VECTOR                 std::vector<T100ProjectInfo*>

class T100ProjectInfo
{
    public:
        T100ProjectInfo();
        virtual ~T100ProjectInfo();

        T100VOID                    SetOpened(T100BOOL);
        T100BOOL                    IsOpened();

        T100VOID                    SetLabel(const T100WSTRING& label);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING& path);
        const T100WSTRING&          GetPath();

        T100VOID                    SetFileName(const T100WSTRING& path);
        const T100WSTRING&          GetFileName();

        T100FILE_INFO_VECTOR&       GetFiles();
        T100FOLDER_INFO_VECTOR&     GetSubFolders();

    protected:
        std::atomic_bool            m_opened;
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;
        T100WSTRING                 m_filename;

        T100FILE_INFO_VECTOR        m_files;
        T100FOLDER_INFO_VECTOR      m_folders;

    private:
        T100VOID                    init();
        T100VOID                    uninit();
};

#endif // T100PROJECTINFO_H
