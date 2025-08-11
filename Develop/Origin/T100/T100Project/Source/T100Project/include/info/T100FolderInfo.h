#ifndef T100FOLDERINFO_H
#define T100FOLDERINFO_H

#include <vector>
#include "T100Common.h"

#define     T100FOLDER_INFO_VECTOR                  std::vector<T100FolderInfo*>

class T100FolderInfo
{
    public:
        T100FolderInfo();
        virtual ~T100FolderInfo();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetPath(const T100WSTRING&);
        const T100WSTRING&      GetPath();

    protected:
        T100WSTRING             m_label;
        T100WSTRING             m_path;

    private:
};

#endif // T100FOLDERINFO_H
