#ifndef T100FILEINFO_H
#define T100FILEINFO_H

#include <vector>
#include "T100Common.h"

#define     T100FILE_INFO_VECTOR                    std::vector<T100FileInfo*>

class T100FileInfo
{
    public:
        T100FileInfo();
        virtual ~T100FileInfo();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetFileName(const T100WSTRING&);
        const T100WSTRING&      GetFileName();

        T100VOID                SetExtName(const T100WSTRING&);
        const T100WSTRING&      GetExtName();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

        T100VOID                SetFile(const T100WSTRING&);
        const T100WSTRING&      GetFile();

    protected:
        T100WSTRING             m_label;
        T100WSTRING             m_filename;
        T100WSTRING             m_path;
        T100WSTRING             m_file;
        T100WSTRING             m_extname;

    private:
};

#endif // T100FILEINFO_H
