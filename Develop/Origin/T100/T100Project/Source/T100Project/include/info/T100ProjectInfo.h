#ifndef T100PROJECTINFO_H
#define T100PROJECTINFO_H

#include "T100FileInfo.h"
#include "T100FolderInfo.h"

#define     T100PROJECT_INFO_VECTOR                 std::vector<T100ProjectInfo*>

class T100ProjectInfo
{
    public:
        T100ProjectInfo();
        virtual ~T100ProjectInfo();

        T100VOID                    SetLabel(const T100WSTRING& label);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING& path);
        const T100WSTRING&          GetPath();

        T100VOID                    SetFileName(const T100WSTRING& path);
        const T100WSTRING&          GetFileName();

    protected:
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;
        T100WSTRING                 m_filename;

        T100FILE_INFO_VECTOR        m_files;
        T100FOLDER_INFO_VECTOR      m_folders;

    private:
};

#endif // T100PROJECTINFO_H
