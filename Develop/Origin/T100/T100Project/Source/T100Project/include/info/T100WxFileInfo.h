#ifndef T100WXFILEINFO_H
#define T100WXFILEINFO_H

#include "T100Common.h"

class T100WxFileInfo
{
    public:
        T100WxFileInfo();
        virtual ~T100WxFileInfo();

        T100VOID                    SetLabel(const T100WSTRING&);
        const T100WSTRING&          GetLabel();

        T100VOID                    SetPath(const T100WSTRING&);
        const T100WSTRING&          GetPath();

    protected:
        T100WSTRING                 m_label;
        T100WSTRING                 m_path;

    private:
};

#endif // T100WXFILEINFO_H
