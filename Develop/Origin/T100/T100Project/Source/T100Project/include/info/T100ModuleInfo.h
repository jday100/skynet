#ifndef T100MODULEINFO_H
#define T100MODULEINFO_H

#include "T100FileInfo.h"

class T100ModuleInfo
{
    public:
        T100ModuleInfo();
        virtual ~T100ModuleInfo();

        T100VOID                SetLabel(const T100WSTRING&);
        const T100WSTRING&      GetLabel();

        T100VOID                SetIncludeFile(T100FileInfo*);
        T100FileInfo*           GetIncludeFile();

        T100VOID                SetSourceFile(T100FileInfo*);
        T100FileInfo*           GetSourceFile();

    protected:
        T100WSTRING             m_label;
        T100FileInfo*           m_fileInclude       = T100NULL;
        T100FileInfo*           m_fileSource        = T100NULL;

    private:
};

#endif // T100MODULEINFO_H
