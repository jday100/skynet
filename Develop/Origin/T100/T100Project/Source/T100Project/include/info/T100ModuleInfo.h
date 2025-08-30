#ifndef T100MODULEINFO_H
#define T100MODULEINFO_H

#include "T100Common.h"

class T100ModuleInfo
{
    public:
        T100ModuleInfo();
        virtual ~T100ModuleInfo();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

    protected:
        T100WSTRING             m_label;

    private:
};

#endif // T100MODULEINFO_H
