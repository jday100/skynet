#ifndef T100FILEINFO_H
#define T100FILEINFO_H

#include <atomic>
#include <vector>
#include "T100Common.h"

#define     T100FILE_INFO_VECTOR                    std::vector<T100FileInfo*>

class T100FileInfo
{
    public:
        T100FileInfo();
        virtual ~T100FileInfo();

        T100VOID                SetOpened(T100BOOL);
        T100BOOL                IsOpened();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetFileName(const T100WSTRING&);
        const T100WSTRING&      GetFileName();

        T100VOID                SetExtName(const T100WSTRING&);
        const T100WSTRING&      GetExtName();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100VOID                SetFolder(const T100WSTRING&);
        const T100WSTRING&      GetFolder();

    protected:
        std::atomic_bool        m_opened;
        T100WSTRING             m_label;
        T100WSTRING             m_filename;
        T100WSTRING             m_path;
        T100WSTRING             m_folder;
        T100WSTRING             m_extname;

    private:
        T100VOID                init();
        T100VOID                uninit();
};

#endif // T100FILEINFO_H
