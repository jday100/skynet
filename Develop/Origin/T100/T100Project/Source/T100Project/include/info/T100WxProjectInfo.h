#ifndef T100WXPROJECTINFO_H
#define T100WXPROJECTINFO_H

#include "T100Common.h"

class T100WxProjectInfo
{
    public:
        T100WxProjectInfo();
        virtual ~T100WxProjectInfo();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

    protected:
        T100WSTRING             m_label;

    private:
};

#endif // T100WXPROJECTINFO_H
