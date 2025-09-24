#ifndef T100WXFOLDERINFO_H
#define T100WXFOLDERINFO_H

#include "T100Common.h"

class T100WxFolderInfo
{
    public:
        T100WxFolderInfo();
        virtual ~T100WxFolderInfo();

        T100VOID                    SetLabel(const T100WSTRING&);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

    protected:
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;

    private:
};

#endif // T100WXFOLDERINFO_H
